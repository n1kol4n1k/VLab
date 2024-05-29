#include "ErlenmeyerFlask.h"

void AErlenmeyerFlask::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Erl. Flask is clicked!");
}
