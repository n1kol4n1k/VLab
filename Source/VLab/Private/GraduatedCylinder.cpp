#include "GraduatedCylinder.h"

void AGraduatedCylinder::NotifyActorOnClicked(FKey ButtonPressed)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Grad. Cyl. is clicked!");
}
