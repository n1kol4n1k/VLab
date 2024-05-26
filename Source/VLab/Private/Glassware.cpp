#include "Glassware.h"
#include "KismetProceduralMeshLibrary.h"

void AGlassware::SetStaticMeshComponents(UStaticMeshComponent* inContainer, UStaticMeshComponent* inFill)
{
	if (IsValid(inContainer) && IsValid(inFill))
	{
		mContainerMesh = inContainer;
		mFillMesh = inFill;
		mFillMesh->SetVisibility(false);
		UKismetProceduralMeshLibrary::CopyProceduralMeshFromStaticMeshComponent(mFillMesh, 0, mEditableFillMesh, false);
	}
	else
	{
		ensureAlwaysMsgf(false, TEXT("Invalid mesh components"));
	}
}

void AGlassware::SetFillPercentage(float inFillPercengate)
{
	mFillPercentage = inFillPercengate;
}
