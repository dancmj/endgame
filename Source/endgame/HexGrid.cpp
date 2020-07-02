// Fill out your copyright notice in the Description page of Project Settings.


#include "HexGrid.h"

// Sets default values
AHexGrid::AHexGrid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AHexGrid::~AHexGrid() {

}

// Called when the game starts or when spawned
void AHexGrid::BeginPlay()
{
	Super::BeginPlay();

	CreateGrid(FShape::Hexagon, 100);
}



void AHexGrid::CreateGrid(FShape shape, int val)
{
    int map_radius = val;

    switch(shape) {
        case(FShape::Hexagon):

        for(int q = -map_radius; q <= map_radius; q++) {
            int r1 = FMath::Max3(-map_radius, -q -map_radius, -map_radius);
            int r2 = FMath::Min3(map_radius, -q + map_radius, map_radius);
            for(int r = r1; r<=r2; r++) {
                hexTable.AddHex(FHexData(Hex(q, r, -q-r)));
            }
        }

		break;
	case(FShape::Parallelogram):
		break;
	case(FShape::Triangle):
		break;
	case(FShape::Rectangle):
		break;
	}

    for (auto& hex : hexTable.map)
    {

        UE_LOG(LogTemp, Warning, TEXT("(\"%s\", q:%d r:%d s:%d)\n"),
               *hex.Key,
               hex.Value.hex.q,
               hex.Value.hex.r,
               hex.Value.hex.s);
    }

	//APawn* newHex = GetWorld()->SpawnActor<APawn>();
	//tileData_1 = GetWorld()->SpawnActor<ATile>(ATile::StaticClass());
	//tileData_2 = GetWorld()->SpawnActor<ATile>(ATile::StaticClass());
}



// Called every frame
void AHexGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
