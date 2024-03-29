// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile.h"
ATile::ATile() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATile::Initialize(int q, int r) {
	Q = q;
	R = r;
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay(); 
	
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FString ATile::GetKey() {
	return FString::FromInt(Q) +"_"+ FString::FromInt(R);
}

