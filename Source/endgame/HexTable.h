// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Map.h"
#include "Containers/UnrealString.h"
#include <endgame\HexLib.h>


struct HexData {
	int foo;
	HexData(int foo_) : foo(foo_) {}
};
/**
 * 
 */
class HexTable
{
public:
	TMap<FString, HexData*> map;
	HexTable();
	~HexTable();

	void AddHex(Hex hex, HexData* data);

	HexData* GetHexData(Hex hex);
	bool Contains(Hex hex);
protected:
	HexData* GetHexData(int q, int r);

	bool Contains(int q, int r);

	FString MakeKey(Hex hex);

	FString MakeKey(int q, int r);
};
