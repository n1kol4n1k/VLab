#pragma once

#include "CoreMinimal.h"
#include "Glassware.h"
#include "ErlenmeyerFlask.generated.h"

UCLASS()
class VLAB_API AErlenmeyerFlask : public AGlassware
{
	GENERATED_BODY()
protected:
	virtual void NotifyActorOnClicked(FKey ButtonPressed = EKeys::LeftMouseButton) override;

public:
};
