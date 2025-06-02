


#include "TheThirdSpacePawn.h"


// Sets default values
ATheThirdSpacePawn::ATheThirdSpacePawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATheThirdSpacePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATheThirdSpacePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATheThirdSpacePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

