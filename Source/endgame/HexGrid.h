// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.h"
#include <endgame\HexTable.h>
#include "HexGrid.generated.h"

UCLASS()
class AHexGrid : public AActor
{
	GENERATED_BODY()

	HexTable hexTable;

public:	
	// Sets default values for this actor's properties
	AHexGrid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	void CreateGrid();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//////////////////////////////////////////// Store Hex(q, r) in hash_table(hash(q,r)).
};