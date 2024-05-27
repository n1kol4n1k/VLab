#include "Beaker.h"
#include "KismetProceduralMeshLibrary.h"

void ABeaker::OnClick()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Beaker is clicked!");
}