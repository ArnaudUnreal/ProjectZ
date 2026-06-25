// Copyright Arnaud Szobad 2026. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "GridDatas.h"
#include "Subsystems/WorldSubsystem.h"
#include "GridSubsystem.generated.h"

UCLASS()
class SUBSYSTEMS_API UGridSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	UGridSubsystem();
	
	UFUNCTION()
	void ComputeGrid();
	FGridCell* GetCellByLocation(const FVector& WorldLocation);
	
	UFUNCTION()
	static FVector GetLocationByCell(const FGridCell& Cell);

private:
	UPROPERTY()
	int CellsXCount;
	UPROPERTY()
	int CellsYCount;
	UPROPERTY()
	FGrid Grid;
	UPROPERTY()
	TMap<FIntPoint, FGridCell> OccupiedCells;
};
