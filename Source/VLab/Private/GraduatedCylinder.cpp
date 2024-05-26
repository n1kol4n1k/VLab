// Fill out your copyright notice in the Description page of Project Settings.


#include "GraduatedCylinder.h"

void AGraduatedCylinder::OnClick()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Grad. Cyl. is clicked!");
}
