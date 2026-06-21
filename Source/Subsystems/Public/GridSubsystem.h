// Copyright Arnaud Szobad 2026. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GridSubsystem.generated.h"

/**
 * 
 */

USTRUCT()
struct FGridCell
{
	GENERATED_BODY()
	UPROPERTY()
	int32 CellID;
	UPROPERTY()
	FIntPoint Coordinates;
	
	FGridCell() = default;
	FGridCell(int32 CellID, FIntPoint Coordinates) : 
		CellID(CellID), Coordinates(Coordinates) {}
	
	int32 GetCellID()
	{
		return CellID; 
	}
	
	FIntPoint GetCoordinates()
	{
		return Coordinates;
	}
	
};


UCLASS()
class SUBSYSTEMS_API UGridSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	UGridSubsystem();
	
	UFUNCTION()
	void ComputeGrid();
	
private:
	UPROPERTY()
	int CellsXCount;
	UPROPERTY()
	int CellsYCount;
	UPROPERTY()
	TArray<FIntPoint> Cells;
};
