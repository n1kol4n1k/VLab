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
	void SetStaticMeshComponents(UStaticMeshComponent* inContainer, UStaticMeshComponent* inFill);

	void SetFillPercentage(float inFillPercengate);

private:
	float mFillPercentage = 1.0f;
};
