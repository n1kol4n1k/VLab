#pragma once

#include "CoreMinimal.h"
#include "Glassware.h"
#include "ErlenmeyerFlask.generated.h"

UCLASS()
class VLAB_API AErlenmeyerFlask : public AGlassware
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
