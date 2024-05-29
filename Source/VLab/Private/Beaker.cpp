#include "Beaker.h"
#include "KismetProceduralMeshLibrary.h"

void ABeaker::NotifyActorOnClicked(FKey ButtonPressed)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Freaker is clicked!");
}
