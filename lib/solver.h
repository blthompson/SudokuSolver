#ifndef __SOLVER_H__
#define __SOLVER_H__

int SolvePuzzle(char aRows[9][10]);

int PopulateTiles(Board * pBoard, char aRows[9][10]);

int PopulateRows(Board * pBoard);

int PopulateCols(Board * pBoard);

int PopulateSquares(Board * pBoard);

void PrintBoardTileVals(Board stToPrint);

void PrintBoardRowVals(Board stToPrint);

void PrintBoardColVals(Board stToPrint);

void PrintBoardSquareVals(Board stToPrint);

void TestPrint(Board stToPrint);

#endif