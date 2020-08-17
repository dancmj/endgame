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

	
public:	
	// Sets default values for this actor's properties
	AHexGrid();
	~AHexGrid();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HexGridSettings)
	const TSubclassOf<class ATile> TileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HexGridSettings, meta = (ClampMin = "1", UIMin = "1"))
		int hex_radius = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HexGridSettings, meta = (ClampMin = "1", UIMin = "1"))
		int map_radius = 20;
	//UFUNCTION(BlueprintCallable, CallInEditor)
	//void DrawHex();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//////

	/////////////  e_game   //////////////////////
	    UFUNCTION(BlueprintCallable)
	void CreateGrid(FShape shape, int radius);

		UPROPERTY(BlueprintReadOnly)
	UHexTable* hexTable;
	//bool PlaceTile(ATile* tile);
	//ATile GetTile(int q, int r);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    ///TODO Store everything inside a hash table easily obtainable.
};
