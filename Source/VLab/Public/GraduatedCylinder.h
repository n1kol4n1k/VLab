#pragma once

#include "CoreMinimal.h"
#include "Glassware.h"
#include "GraduatedCylinder.generated.h"

UCLASS()
class VLAB_API AGraduatedCylinder : public AGlassware
{
	GENERATED_BODY()
protected:
	virtual void NotifyActorOnClicked(FKey ButtonPressed = EKeys::LeftMouseButton) override;

};
