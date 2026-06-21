// Copyright Arnaud Szobad 2026. All rights reserved. 


#include "GridSubsystem.h"

UGridSubsystem::UGridSubsystem()
{
	CellsXCount = 4;
	CellsYCount = 3;
}

void UGridSubsystem::ComputeGrid()
{
	for (int x = 0; x < CellsXCount; x++)
	{
		for (int y = 0; y < CellsYCount; y++)
		{
			Cells.Add(FIntPoint(x,y));
		}
	}
}
