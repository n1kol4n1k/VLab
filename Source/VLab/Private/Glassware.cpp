#include "Glassware.h"
#include "KismetProceduralMeshLibrary.h"
#include "ProceduralMeshComponent.h"

void AGlassware::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickEnabled(mIsDragging);
	mPlayerController = GetWorld()->GetFirstPlayerController();
}

void AGlassware::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (mIsDragging)
	{
		static FVector MousePosition;
		static FVector MouseDirection;
		mPlayerController->DeprojectMousePositionToWorld(MousePosition, MouseDirection);
	
		FVector newLocation = FMath::LinePlaneIntersection(MousePosition,
			MousePosition + (MouseDirection * 5000),
			mInitialLocation + FVector{0, 0, 20},
			GetActorUpVector());

		SetActorLocation(newLocation);
	}
}

void AGlassware::NotifyActorOnClicked(FKey ButtonPressed)
{
	static constexpr float TimerDuration = 2.f;

	GetWorldTimerManager().SetTimer(RegisterDragTimerHandle, FTimerDelegate::CreateLambda([this]()
		{
			mIsDragging = true;
			SetActorTickEnabled(mIsDragging);

			mInitialLocation = GetActorLocation();
			//AddActorWorldOffset({ -15, 0, 5 });
		}), TimerDuration, false);
}

void AGlassware::NotifyActorOnReleased(FKey ButtonPressed)
{
	GetWorldTimerManager().ClearTimer(RegisterDragTimerHandle);

	if (mIsDragging)
	{
		SetActorLocation(mInitialLocation);
	}

	mIsDragging = false;
	SetActorTickEnabled(mIsDragging);
}

void AGlassware::NotifyActorEndCursorOver()
{
	GetWorldTimerManager().ClearTimer(RegisterDragTimerHandle);
}

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

