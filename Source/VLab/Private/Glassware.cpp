#include "Glassware.h"
#include "KismetProceduralMeshLibrary.h"
#include "ProceduralMeshComponent.h"

void AGlassware::SetStaticMeshComponents(UStaticMeshComponent* inContainer, UStaticMeshComponent* inFill, UProceduralMeshComponent* inProceduralFill)
{
	if (IsValid(inContainer) && IsValid(inFill))
	{
		mContainerMesh = inContainer;
		mFillMesh = inFill;
		mFillMesh->SetVisibility(false);
		mEditableFillMesh = inProceduralFill;

		UKismetProceduralMeshLibrary::CopyProceduralMeshFromStaticMeshComponent(mFillMesh, 0, mEditableFillMesh, false);
		mEditableFillMesh->SetRelativeTransform(mFillMesh->GetRelativeTransform());
	}
	else
	{
		ensureAlwaysMsgf(false, TEXT("Invalid mesh components"));
	}
}

void AGlassware::SetFillPercentage(float inFillPercengate)
{
	if (!IsValid(mFillMesh) || !IsValid(mEditableFillMesh))
	{
		return;
	}

	if (inFillPercengate > mFillPercentage)
	{
		UKismetProceduralMeshLibrary::CopyProceduralMeshFromStaticMeshComponent(mFillMesh, 0, mEditableFillMesh, false);
	}

	mFillPercentage = inFillPercengate;

	const FBoxSphereBounds& fillMeshBounds = mFillMesh->Bounds;
	FVector planePosition = fillMeshBounds.Origin - fillMeshBounds.BoxExtent + (2 * fillMeshBounds.BoxExtent * inFillPercengate);

	UKismetProceduralMeshLibrary::SliceProceduralMesh(mEditableFillMesh, planePosition, -mFillMesh->GetUpVector(), false, mEditableFillMesh, EProcMeshSliceCapOption::UseLastSectionForCap, nullptr);
}

//DEBUG
void AGlassware::PostEditChangeProperty(FPropertyChangedEvent& e)
{
	FName PropertyName = (e.Property != NULL) ? e.Property->GetFName() : NAME_None;
	if (PropertyName == GET_MEMBER_NAME_CHECKED(AGlassware, mDebugFillPercentage))
	{
		const float debugPerc = mDebugFillPercentage / 100.f;
		//To prevent flicker effect when calling this too fast
		if (FMath::Abs(debugPerc - mFillPercentage) > 0.01)
		{
			SetFillPercentage(debugPerc);
		}
	}
	Super::PostEditChangeProperty(e);
}