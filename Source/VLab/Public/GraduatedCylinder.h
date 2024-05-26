// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Glassware.h"
#include "GraduatedCylinder.generated.h"

/**
 * 
 */
UCLASS()
class VLAB_API AGraduatedCylinder : public AGlassware
{
	GENERATED_BODY()
protected:
	virtual void OnClick() override;
};
