// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/ConstructorHelpers.h"
#include <endgame\HexLib.h>
#include "Tile.generated.h"
#ifndef TILE_SETTINGS
#define TILE_SETTINGS "Tile Settings"
#endif

UCLASS(abstract)
class ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();
	UFUNCTION(BlueprintCallable, Category = TILE_SETTINGS)
	void Initialize(int q, int r);

	Hex* hex;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = TILE_SETTINGS)
	int Q;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = TILE_SETTINGS)
	int R;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = TILE_SETTINGS)
	FString GetKey();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
