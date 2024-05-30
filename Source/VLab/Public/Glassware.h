#pragma once

#include "CoreMinimal.h"
#include "LabTool.h"
#include "Glassware.generated.h"


UCLASS(Abstract)
class VLAB_API AGlassware : public ALabTool
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorOnClicked(FKey ButtonPressed = EKeys::LeftMouseButton) override;
	virtual void NotifyActorOnReleased(FKey ButtonPressed = EKeys::LeftMouseButton) override;
	virtual void NotifyActorEndCursorOver() override;

private:
	UPROPERTY(Transient)
	UStaticMeshComponent* mContainerMesh = nullptr;

	UPROPERTY(Transient)
	UStaticMeshComponent* mFillMesh = nullptr;

	UPROPERTY(Transient)
	class UProceduralMeshComponent* mEditableFillMesh = nullptr;

	float mFillPercentage = 1.0f;

	bool mIsDragging = false;

	FTimerHandle RegisterDragTimerHandle;

	FVector mInitialLocation{};

protected:
	UFUNCTION(BlueprintCallable)
	void SetStaticMeshComponents(UStaticMeshComponent* inContainer, UStaticMeshComponent* inFill, class UProceduralMeshComponent* inProceduralFill);
	
	UFUNCTION(BlueprintCallable)
	void SetFillPercentage(float inFillPercengate);

	APlayerController* mPlayerController = nullptr;

	//DEBUG
private:
	UPROPERTY(EditAnywhere, meta = (ClampMin = "0", ClampMax = "100", UIMin = "0", UIMax = "100"))
	int mDebugFillPercentage = 0;
protected:
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& e) override;

};
