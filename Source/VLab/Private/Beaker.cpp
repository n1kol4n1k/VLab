#include "Beaker.h"
#include "KismetProceduralMeshLibrary.h"

void ABeaker::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Freaker is clicked!");
}
