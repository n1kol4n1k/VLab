#include "TestTube.h"

void ATestTube::NotifyActorOnClicked(FKey ButtonPressed)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "TestTube is clicked!");
}
