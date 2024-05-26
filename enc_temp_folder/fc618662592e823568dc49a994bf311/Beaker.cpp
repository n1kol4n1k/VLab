#include "Beaker.h"

void ABeaker::OnClick()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Beaker is clicked!");
}

void ABeaker::SetProcMesh(UProceduralMeshComponent* in)
{
	mEditableFillMesh = in;
}
