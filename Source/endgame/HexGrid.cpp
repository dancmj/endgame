// Fill out your copyright notice in the Description page of Project Settings.


#include "HexGrid.h"

// Sets default values
AHexGrid::AHexGrid() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//static ConstructorHelpers::FObjectFinder<UClass> TileClassFinder(TEXT("Blueprint'/Game/Blueprints/BP_Tile.BP_Tile'"));
	//TileClass= TileClassFinder.Object;
}

AHexGrid::~AHexGrid() {
	//hexTable->~UHexTable();
}

// Called when the game starts or when spawned
void AHexGrid::BeginPlay()
{
	Super::BeginPlay();

	//CreateGrid(FShape::Hexagon, map_radius);
}

/// <summary>
/// 
/// </summary>
/// <param name="shape"></param>
/// <param name="radius"></param>
void AHexGrid::CreateGrid(FShape shape, int	radius)
{
	///TODO this is odd. hexTable should be perhaps declared only once. Use something to clean it up?..
	/// Game crashes when using CreateGrid without hexTable being declared in here.....................
	/// FIXME!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	hexTable = NewObject<UHexTable>();

	switch (shape) {
	default:
	case(FShape::Hexagon):

		for (int q = -radius; q <= radius; q++) {
			int r1 = FMath::Max3(-radius, -q - radius, -radius);
			int r2 = FMath::Min3(radius, -q + radius, radius);
			for (int r = r1; r <= r2; r++) {
				FHexData* data = new FHexData();
				Hex* hex = new Hex(q, r, -q - r);

				data->Init(hex);
				hexTable->AddHex(data);
			}
		}
		//		UE_LOG(LogTemp, Warning, TEXT(" Separation Vector (q%d,r%d,s%d)\n"), separation_vector.X, separation_vector.Y, separation_vector.Z);

		//		FVector Location(q * separation_vector.X + (separation_vector.X/2 * r), r * (separation_vector.Y), -100.0f);
		//		FRotator Rotation(0.0f, 0.0f, 0.0f);
		//		FActorSpawnParameters SpawnInfo;

		//		ATile* tile = GetWorld()->SpawnActorDeferred<ATile>(TileClass, FTransform(Rotation, Location));
		//		if (tile != nullptr) {
		//			tile->Initialize(q, r);
		//			tile->FinishSpawning(FTransform(Rotation, Location));
		//		}
		//	} 
		//}

		break;
	case(FShape::Parallelogram):
		break;
	case(FShape::Triangle):
		break;
	case(FShape::Rectangle):
		break;
	}

	for (auto& hex : hexTable->map) {

		UE_LOG(LogTemp, Warning, TEXT("(\"%s\", q:%d r:%d s:%d)\n"),
			*hex.Key,
			hex.Value.hex->q,
			hex.Value.hex->r,
			hex.Value.hex->s);
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


//bool AHexGrid::PlaceTile(ATile* tile) {
//
//}

//ATile AHexGrid::GetTile(int q, int r) {
//	//return tile_map[q][r]
//}