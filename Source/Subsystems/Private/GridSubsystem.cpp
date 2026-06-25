// Copyright Arnaud Szobad 2026. All rights reserved. 


#include "GridSubsystem.h"
#include "SharedDatas/Public/GridDatas.h"

UGridSubsystem::UGridSubsystem()
{
	CellsXCount = 4;
	CellsYCount = 3;
}

void UGridSubsystem::ComputeGrid()
{
	Grid.SetCellsCountX(CellsXCount);
	Grid.SetCellsCountY(CellsYCount);
	
	for (int x = 0; x < CellsXCount; x++)
	{
		for (int y = 0; y < CellsYCount; y++)
		{
			FGridCell cell = FGridCell(x + y * CELL_SIZE, FIntPoint(x, y), 0);
			Grid.AddCell(FIntPoint(x, y), cell);
		}
	}
}

FGridCell* UGridSubsystem::GetCellByLocation(const FVector& WorldLocation)
{
	const FIntPoint TmpPoint =  FIntPoint(
		FMath::FloorToInt(WorldLocation.X / CELL_SIZE),
		FMath::FloorToInt(WorldLocation.Y / CELL_SIZE)
	);
	return Grid.GetCell(TmpPoint);
}

FVector UGridSubsystem::GetLocationByCell(const FGridCell& Cell)
{
	return FVector(
		Cell.GetCoordinates().X * CELL_SIZE,
		Cell.GetCoordinates().Y * CELL_SIZE,
		0.f);
}