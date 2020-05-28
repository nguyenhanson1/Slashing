

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorSwitch.generated.h"

UCLASS()
class SLASHING_API AFloorSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorSwitch();

	/** Overlap volume for the functionality to be triggered */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite. Category = "Floor Switch")
	class UBoxComponent* TriggerBox;

	/** Switch for the character to step on*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite.Category = "Floor Switch")
	class UStaticMeshComponent* FloorSwitch;

	/**  */
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
