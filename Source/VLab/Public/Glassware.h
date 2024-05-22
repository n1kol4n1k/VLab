#pragma once

#include "CoreMinimal.h"
#include "LabTool.h"
#include "Glassware.generated.h"

UCLASS()
class VLAB_API AGlassware : public ALabTool
{
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* mContainerMesh = nullptr;

	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* mFillMesh = nullptr;

	UFUNCTION(BlueprintCallable)
	void SetStaticMeshComponents(UStaticMeshComponent* inContainer, UStaticMeshComponent* inFill);
};
