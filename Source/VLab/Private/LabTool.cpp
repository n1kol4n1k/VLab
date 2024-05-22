#include "LabTool.h"

// Sets default values
ALabTool::ALabTool()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void ALabTool::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "HELLOoo!");
	
}

void ALabTool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

