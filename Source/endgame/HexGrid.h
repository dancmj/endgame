// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.h"
#include <endgame\HexTable.h>
#include "HexGrid.generated.h"

    UENUM()
enum FShape {
	Hexagon,
	Parallelogram,
	Triangle,
	Rectangle,
};

    UCLASS()
class AHexGrid : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, meta = (ClampMin = "1", UIMin = "1"))
	int map_radius = 0;
		UPROPERTY(EditAnywhere, meta = (ClampMin = "1", UIMin = "1"))
	FVector separation_vector;
	AHexTable hexTable;
public:	
	// Sets default values for this actor's properties
	AHexGrid();
	~AHexGrid();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
	TSubclassOf<class ATile> TileClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	/////////////  e_game   //////////////////////
	    UFUNCTION(BlueprintCallable)
	void CreateGrid(FShape shape, int val);

	//bool PlaceTile(ATile* tile);
	//ATile GetTile(int q, int r);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    ///TODO Store everything inside a hash table easily obtainable.
};
