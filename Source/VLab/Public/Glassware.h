#pragma once

#include "CoreMinimal.h"
#include "LabTool.h"
#include "Glassware.generated.h"


UCLASS(Abstract)
class VLAB_API AGlassware : public ALabTool
{
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* mContainerMesh = nullptr;

	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* mFillMesh = nullptr;

	UPROPERTY()
	class UProceduralMeshComponent* mEditableFillMesh = nullptr;

	UFUNCTION(BlueprintCallable)
	void SetStaticMeshComponents(UStaticMeshComponent* inContainer, UStaticMeshComponent* inFill, class UProceduralMeshComponent* inProceduralFill);
	
	UFUNCTION(BlueprintCallable)
	void SetFillPercentage(float inFillPercengate);

	//DEBUG
	UPROPERTY(EditAnywhere, meta = (ClampMin = "0", ClampMax = "100", UIMin = "0", UIMax = "100"))
	int mDebugFillPercentage = 0;

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& e) override;

private:
	float mFillPercentage = 1.0f;
};
