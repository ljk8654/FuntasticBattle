#include "Bomb.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/SphereComponent.h"
#include "TimerManager.h"
#include "ShoorterCharater.h"

ABomb::ABomb()
{
    PrimaryActorTick.bCanEverTick = false;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;
    Mesh->SetSimulatePhysics(true);
    Mesh->SetCollisionProfileName(TEXT("PhysicsActor"));
	

    PickupSphere = CreateDefaultSubobject<USphereComponent>(TEXT("PickupSphere"));
    PickupSphere->SetupAttachment(RootComponent);
    PickupSphere->SetSphereRadius(60.f);
    PickupSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	PickupSphere->SetCollisionObjectType(ECC_WorldDynamic);
    PickupSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
    PickupSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
    PickupSphere->OnComponentBeginOverlap.AddDynamic(this, &ABomb::OnPickupOverlap);

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->bShouldBounce = true;
    ProjectileMovement->ProjectileGravityScale = 1.2f;
}

void ABomb::BeginPlay()
{
    Super::BeginPlay();
    bFuseStarted = false;    // 시작시 타이머 OFF
	UE_LOG(LogTemp, Warning, TEXT("Collision: %d, Physics: %d"),
  (int)Mesh->GetCollisionEnabled(), 
  (int)Mesh->IsSimulatingPhysics());
    StopFuse();
}

// 플레이어가 오버랩하면 획득
void ABomb::OnPickupOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
    AShoorterCharater* Player = Cast<AShoorterCharater>(OtherActor);
    if (Player)
    {
		UE_LOG(LogTemp, Warning, TEXT("플레이어가 폭탄에 닿음!"));
		OnPickedUp();
        Player->PickupBomb(this);

    }
}

// 플레이어가 폭탄을 손에 든 상태
void ABomb::OnPickedUp()
{

    SetActorHiddenInGame(false);
	Mesh->SetSimulatePhysics(false);
    Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    StopFuse();  // 들고 있을 땐 타이머 멈춤
    ProjectileMovement->Deactivate();
    Mesh->SetSimulatePhysics(false);
}

// 플레이어가 폭탄을 던질 때
void ABomb::OnThrown()
{
    Mesh->SetSimulatePhysics(false);
    Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    Mesh->SetSimulatePhysics(true);

    FVector ThrowDir = GetActorForwardVector() + FVector(0,0,0.8f);
    ThrowDir.Normalize();
    Mesh->AddImpulse(ThrowDir * 700.f, NAME_None, true);

    StartFuse();
}

void ABomb::StartFuse()
{
    if (!bFuseStarted)
    {
        if (bFuseStarted) return;
        bFuseStarted = true;

        // 심지 소리 재생 (루프)
        if (FuseSound)
    {
        FuseAudioComponent = UGameplayStatics::SpawnSoundAttached(
            FuseSound,
            RootComponent,                // 폭탄에 붙임
            NAME_None,
            FVector::ZeroVector,
            EAttachLocation::KeepRelativeOffset,
            true,                         // 액터 파괴 시 자동 종료
            1.0f,                         // Volume
            1.0f,                         // Pitch
            0.0f,
            FuseAttenuation               // 거리 기반 소리
        );
    }


        GetWorld()->GetTimerManager().SetTimer(
            ExplosionTimerHandle,
            this,
            &ABomb::Explode,
            FuseTime,
            false
        );
    }
}

void ABomb::StopFuse()
{
    bFuseStarted = false;
    GetWorld()->GetTimerManager().ClearTimer(ExplosionTimerHandle);

    // 심지 소리 정지
    if (FuseAudioComponent)
    {
        FuseAudioComponent->Stop();
        FuseAudioComponent = nullptr;
    }
}

void ABomb::Explode()
{
    // 심지 소리 정지
    if (FuseAudioComponent)
    {
        FuseAudioComponent->Stop();
        FuseAudioComponent = nullptr;
    }

    // 폭발음 재생
    if (ExplosionSound)
    {
        UGameplayStatics::PlaySoundAtLocation(
            this,
            ExplosionSound,
            GetActorLocation(),
            1.0f,
            1.0f,
            0.0f,
            ExplosionAttenuation 
);
    }
    // 폭발 이펙트
    if (ExplosionEffect)
    {
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(
            GetWorld(),
            ExplosionEffect,
            GetActorLocation()
        );
    }

    // 데미지/넉백 처리
    TArray<AActor*> IgnoredActors;
    UGameplayStatics::ApplyRadialDamage(
        this,
        ExplosionDamage,
        GetActorLocation(),
        ExplosionRadius,
        nullptr,
        IgnoredActors,
        this,
        GetInstigatorController(),
        true
    );

    // 넉백(캐릭터)
    TArray<AActor*> OverlappedActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AShoorterCharater::StaticClass(), OverlappedActors);

    FVector ExplosionLocation = GetActorLocation();
    for (AActor* Actor : OverlappedActors)
    {
        float Distance = FVector::Dist(Actor->GetActorLocation(), ExplosionLocation);
        if (Distance <= ExplosionRadius)
        {
            ACharacter* Char = Cast<ACharacter>(Actor);
            if (Char)
            {
                FVector Dir = (Char->GetActorLocation() - ExplosionLocation).GetSafeNormal();
                FVector Knockback = Dir * 1200.f + FVector(0,0,400.f); // 위쪽 힘 포함
                Char->LaunchCharacter(Knockback, true, true);
            }
            else
            {
                UPrimitiveComponent* Prim = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
                if (Prim && Prim->IsSimulatingPhysics())
                {
                    Prim->AddRadialImpulse(ExplosionLocation, ExplosionRadius, 1500.f, ERadialImpulseFalloff::RIF_Linear, true);
                }
            }
        }
    }

    Destroy();
}