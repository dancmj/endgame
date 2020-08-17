// Fill out your copyright notice in the Description page of Project Settings.


#include "HexTable.h"
#include "Containers/UnrealString.h"

UHexTable::UHexTable()
{
}

UHexTable::~UHexTable()
{
}


FHexData* UHexTable::Get(Hex hex) {
	return Get(hex.q, hex.r);
}

FHexData* UHexTable::Get(int q, int r) {
	if (Contains(q, r)) {
		return &map[MakeKey(q, r)];
	}

	return 0;
}

void UHexTable::AddHex(FHexData *data) {
	map.Add(MakeKey(data->hex), *data);
	//UE_LOG(LogTemp, Warning, TEXT(" ADDING HEX (q%d,r%d,s%d)\n"), data->hex->q, data->hex->r, data->hex->s);
	Hex mappedHex = *map.Find(MakeKey(data->hex->q, data->hex->r))->hex;
	UE_LOG(LogTemp, Warning, TEXT(" MAPPED HEX (q%d,r%d,s%d)\n"), mappedHex.q, mappedHex.r, mappedHex.s);
}

bool UHexTable::Contains(Hex* hex) {
	return Contains(hex->q, hex->r);
}

bool UHexTable::Contains(int q, int r) {
	return map.Contains(MakeKey(q, r));
}

FString UHexTable::MakeKey(Hex* hex) {
	return MakeKey(hex->q, hex->r);
}

FString UHexTable::MakeKey(int q, int r) {
	return FString::FromInt(q) +"_"+ FString::FromInt(r);
}

/// <summary>
/// For each one in the map, iterate and then spit out an array of those hexes that already exist in the map.
/// </summary>
/// <param name="data"></param>
TArray<FIntVector> UHexTable::GetHexCoordinates() {
	TArray<FIntVector> data;
	for (const TPair<FString, FHexData> pair : map) {
		int q = pair.Value.hex->q;
		int r = pair.Value.hex->r;
		
		data.Emplace(FIntVector(q, r, -q - r));
		FString key = pair.Key;
		UE_LOG(LogTemp, Warning, TEXT(" Emplacing KEY (%s)\n   CONTAINING: %d,%d"), *key, q, r);
	}

	return data;
}

void UHexTable::GetHexData(int q, int r, FHexData& hexData) {
	hexData = *Get(q, r);
}

void UHexTable::ClearMap() {
	map.Empty();
}