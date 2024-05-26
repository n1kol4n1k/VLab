#include "ErlenmeyerFlask.h"

void AErlenmeyerFlask::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Erlenmeyer!");
	if (mContainerMesh)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Mesh is active in BeginPlay!");
	}
}

void AErlenmeyerFlask::OnClick()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Erl. Flask is clicked!");
}

void AErlenmeyerFlask::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	static bool once = true;
	if (once && mContainerMesh)
	{
		once = false;
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Mesh is active in BeginPlay!");
	}
}
