#include "Glassware.h"

void AGlassware::SetStaticMeshComponents(UStaticMeshComponent* inContainer, UStaticMeshComponent* inFill)
{
	if (IsValid(inContainer) && IsValid(inFill))
	{
		mContainerMesh = inContainer;
		mFillMesh = inFill;
	}
	else
	{
		ensureAlwaysMsgf(false, TEXT("Invalid mesh components"));
	}
}