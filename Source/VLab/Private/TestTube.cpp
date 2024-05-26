#include "TestTube.h"

void ATestTube::OnClick()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "TestTube is clicked!");
}
