#pragma once

#include "CoreMinimal.h"
#include "Glassware.h"
#include "TestTube.generated.h"

UCLASS()
class VLAB_API ATestTube : public AGlassware
{
	GENERATED_BODY()
protected:
	virtual void NotifyActorOnClicked(FKey ButtonPressed = EKeys::LeftMouseButton) override;

};
