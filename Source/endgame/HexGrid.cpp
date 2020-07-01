// Fill out your copyright notice in the Description page of Project Settings.


#include "HexGrid.h"

// Sets default values
AHexGrid::AHexGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHexGrid::BeginPlay()
{
	Super::BeginPlay();
	
	CreateGrid();
}

void AHexGrid::CreateGrid()
{
	/// Next up, spawn the grid elements of the HexTable.

	//APawn* newHex = GetWorld()->SpawnActor<APawn>();
	//tileData_1 = GetWorld()->SpawnActor<ATile>(ATile::StaticClass());
	//tileData_2 = GetWorld()->SpawnActor<ATile>(ATile::StaticClass());
} 



// Called every frame
void AHexGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
