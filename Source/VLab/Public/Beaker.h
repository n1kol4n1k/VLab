#pragma once

#include "CoreMinimal.h"
#include "Glassware.h"
#include "Beaker.generated.h"

UCLASS()
class VLAB_API ABeaker : public AGlassware
{
	GENERATED_BODY()
protected:
	virtual void OnClick() override;

};
