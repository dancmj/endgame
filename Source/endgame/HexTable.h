// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Map.h"
#include "Containers/UnrealString.h"
#include <endgame\HexLib.h>
//#include "HexTable.generated.h"


struct FHexData {

	Hex hex;
	FHexData() : hex(Hex(0, 0, 0)) {}
    FHexData(Hex hex_) : hex(Hex(hex_.q, hex_.r, hex_.s)){
		//UE_LOG(LogTemp, Warning, TEXT("(\"%s\")\n"), hex.q);
	}
};

class AHexTable
{
public:
	TMap<FString, FHexData> map;

	AHexTable();
	~AHexTable();

	FHexData* Get(Hex hex);
	bool Contains(Hex* hex);
    void AddHex(FHexData data);
protected:
	FHexData* Get(int q, int r);

	bool Contains(int q, int r);

	FString MakeKey(Hex* hex);

	FString MakeKey(int q, int r);
};
