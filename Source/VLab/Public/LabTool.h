#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LabTool.generated.h"

UCLASS()
class VLAB_API ALabTool : public AActor
{
	GENERATED_BODY()
	
public:	
	ALabTool();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
