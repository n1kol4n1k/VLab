#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LabTool.generated.h"

UCLASS(Abstract)
class VLAB_API ALabTool : public AActor
{
	GENERATED_BODY()
	
public:	
	ALabTool();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual void OnClick() PURE_VIRTUAL(OnClick, return;);

public:	
	virtual void Tick(float DeltaTime) override;
};
