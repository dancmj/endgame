// Fill out your copyright notice in the Description page of Project Settings.


#include "HexTable.h"
#include "Containers/UnrealString.h"

AHexTable::AHexTable()
{
}

AHexTable::~AHexTable()
{
}


FHexData* AHexTable::Get(Hex hex) {
	return Get(hex.q, hex.r);
}

FHexData* AHexTable::Get(int q, int r) {
	if (Contains(q, r)) {
		return &map[MakeKey(q, r)];
	}

	return 0;
}

void AHexTable::AddHex(FHexData data) {
	map.Add(MakeKey(&data.hex), data);
	UE_LOG(LogTemp, Warning, TEXT(" ADDING HEX (q%d,r%d,s%d)\n"), data.hex.q, data.hex.r, data.hex.s);
}

bool AHexTable::Contains(Hex* hex) {
	return Contains(hex->q, hex->r);
}

bool AHexTable::Contains(int q, int r) {
	return map.Contains(MakeKey(q, r));
}

FString AHexTable::MakeKey(Hex* hex) {
	return MakeKey(hex->q, hex->r);
}

FString AHexTable::MakeKey(int q, int r) {
	return FString::FromInt(q) +"_"+ FString::FromInt(r);
}
