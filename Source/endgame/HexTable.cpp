// Fill out your copyright notice in the Description page of Project Settings.


#include "HexTable.h"
#include "Containers/UnrealString.h"

HexTable::HexTable()
{
}

HexTable::~HexTable()
{
}

void HexTable::AddHex(Hex hex, HexData* data) {
	map.Add(MakeKey(hex), data);
}

HexData* HexTable::GetHexData(Hex hex) {
	return GetHexData(hex.q, hex.r);
}

HexData* HexTable::GetHexData(int q, int r) {
	if (Contains(q, r)) {
		return map[MakeKey(q, r)];
	}

	return 0;
}

bool HexTable::Contains(Hex hex) {
	return Contains(hex.q, hex.r);
}

bool HexTable::Contains(int q, int r) {
	return map.Contains(MakeKey(q, r));
}

FString HexTable::MakeKey(Hex hex) {
	return MakeKey(hex.q, hex.r);
}

FString HexTable::MakeKey(int q, int r) {
	return FString::FromInt(q) + FString::FromInt(r);
}