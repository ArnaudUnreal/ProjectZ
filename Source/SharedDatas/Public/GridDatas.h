#pragma once

#include "CoreMinimal.h"
#include "GridDatas.generated.h"

/**
 * CONSTANTES
 */
constexpr int32 CELL_SIZE = 100;

/**
 * STRUCTURES
 */

// Cell
USTRUCT()
struct FGridCell
{
	GENERATED_BODY()
	
	FGridCell() = default;
	FGridCell(
		int32 CellID,
		const FIntPoint Coordinates,
		int32 SurvivorCount) :
			CellID(CellID),
			Coordinates(Coordinates),
			SurvivorCount(SurvivorCount){}

	int32 GetCellID() const{ return CellID;}
	
	FIntPoint GetCoordinates() const{ return Coordinates;}
	
	int32 GetSurvivorsCount() const{ return SurvivorCount;}
	
	bool IsCellFree() const{ return SurvivorCount == 0;}
	
	void AddSurvivors(int32 Count)
	{
		SurvivorCount += Count;
	}
	
	void RemoveSurvivors(int32 Count)
	{
		SurvivorCount = FMath::Max(0, SurvivorCount - Count);
	}
	
private:
	UPROPERTY()
	int32 CellID = -1;
	UPROPERTY()
	FIntPoint Coordinates = FIntPoint(-1,-1);
	UPROPERTY()
	int32 SurvivorCount = 0;
};

// Grid
USTRUCT()
struct FGrid
{
	GENERATED_BODY()

	FGrid() = default;
	explicit FGrid(
		const TMap<FIntPoint,FGridCell>& InCells,
		int32 InCellsCountX,
		int32 InCellsCountY) :
			Cells(InCells),
			CellsCountX(InCellsCountX),
			CellsCountY(InCellsCountY){}
	
	FGridCell* GetCell(const FIntPoint& Coords)
	{
		return Cells.Find(Coords);
	}

	const FGridCell* GetCell(const FIntPoint& Coords) const
	{
		return Cells.Find(Coords);
	}
	
	void AddCell(const FIntPoint& Coords, const FGridCell& Cell)
	{
		Cells.FindOrAdd(Coords, Cell);
	}
	
	void RemoveCell(const FIntPoint& Coords)
	{
		Cells.Remove(Coords);
	}

	bool IsCellFree(const FIntPoint& Coords) const
	{
		const FGridCell* Cell = Cells.Find(Coords);
		return Cell && Cell->IsCellFree();
	}
	
	static int32 GetCellSurvivorsCount(const FGridCell& Cell)
	{
		return Cell.GetSurvivorsCount();
	}
	
	static void RemoveSurvivorsFromCell(FGridCell& Cell, const int32 Count)
	{
		Cell.RemoveSurvivors(Count);
	}
	
	static void AddSurvivorsToCell(FGridCell& Cell, const int32 Count)
	{
		Cell.AddSurvivors(Count);
	}
	
	static bool IsGridCellFree(const FGridCell& Cell)
	{
		return Cell.IsCellFree();
	}
	
	void SetCellsCountX(int32 InCellsCountX)
	{
		CellsCountX = InCellsCountX;
	}
	void SetCellsCountY(int32 InCellsCountY)
	{
		CellsCountY = InCellsCountY;
	}
	
	int32 GetCellsCountX() const
	{
		return CellsCountX;
	}
	int32 GetCellsCountY() const
	{
		return CellsCountY;
	}

private:
	UPROPERTY()
	TMap<FIntPoint, FGridCell> Cells;
	UPROPERTY()
	int32 CellsCountX;
	UPROPERTY()
	int32 CellsCountY;
};