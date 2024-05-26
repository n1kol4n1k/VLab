#include "Beaker.h"
#include "KismetProceduralMeshLibrary.h"

void ABeaker::OnClick()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Beaker is clicked!");
}

void ABeaker::SetProcMesh(UProceduralMeshComponent* in)
{
	mEditableFillMesh = in;
}

void ABeaker::CutProcMesh(float perc)
{
	const FBoxSphereBounds& fillMeshBounds = mFillMesh->Bounds;
	FVector planePosition = fillMeshBounds.Origin - fillMeshBounds.BoxExtent + (2* fillMeshBounds.BoxExtent * perc);

	UKismetProceduralMeshLibrary::SliceProceduralMesh(mEditableFillMesh, planePosition, -mFillMesh->GetUpVector(), false, mEditableFillMesh, EProcMeshSliceCapOption::NoCap, nullptr);
}
