


#include "Pickup.h"
#include "Main.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"

APickup::APickup()
{
	CoinCount = 1;
}

void APickup::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	
	if (OtherActor)
	{
		AMain* Main = Cast<AMain>(OtherActor);
		if (Main)
		{
			Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
			UE_LOG(LogTemp, Warning, TEXT("Call Pickup::OnOverlapBegin()"));
			if (Super::OverlapSound)
			{
				UGameplayStatics::PlaySound2D(this, Super::OverlapSound);
			}

			Main->IncrementCoins(CoinCount);
			Main->PickupLocations.Add(GetActorLocation());

			Destroy();
		}
	}
}

void APickup::OnOverlapEnd(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	UE_LOG(LogTemp, Warning, TEXT("Call Pickup::OnOverLapEnd()"));
}
