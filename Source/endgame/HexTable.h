// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Map.h"
#include "Containers/UnrealString.h"
#include <endgame\HexLib.h>
#include <endgame\Tile.h>
#include "HexTable.generated.h"
#ifndef HEXTABLE_CATEGORY
#define HEXTABLE_CATEGORY "Hex Table Helpers"
#endif
#ifndef HEX_CATEGORY
#define HEX_CATEGORY "Hex Data"
#endif

USTRUCT(BlueprintType)
struct FHexData {
	GENERATED_BODY()
	Hex* hex;

	void Init(Hex hex_) {
		hex = &hex_;
	}

	void Init(Hex* hex_) {
		hex = hex_;
	}
};

UCLASS()
class UHexTable : public UObject {
	GENERATED_BODY()
public:
	UPROPERTY()
	TMap<FString, FHexData> map;

	UHexTable();
	~UHexTable();

	FHexData* Get(Hex hex);
	bool Contains(Hex* hex);
	void AddHex(FHexData* data);
	bool Contains(int q, int r);
	
	UFUNCTION(BlueprintCallable, Category = HEXTABLE_CATEGORY)
		void GetHexData(int q, int r, FHexData& hexData);
	UFUNCTION(BlueprintCallable, Category = HEXTABLE_CATEGORY)
		TArray<FIntVector> GetHexCoordinates();

	UFUNCTION(BlueprintCallable, Category = HEXTABLE_CATEGORY)
		void ClearMap();
protected:
	FHexData* Get(int q, int r);
	FString MakeKey(Hex* hex);
	FString MakeKey(int q, int r);
};
