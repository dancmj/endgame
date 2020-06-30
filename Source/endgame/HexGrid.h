// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexGrid.generated.h"

UCLASS()
class ENDGAME_API AHexGrid : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AHexGrid();
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category="HexMesh")
	UStaticMeshComponent* sample;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	void CreateHex();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

