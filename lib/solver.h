#ifndef __SOLVER_H__
#define __SOLVER_H__

int SolvePuzzle(char aRows[9][10]);

int PopulateTiles(Board * pBoard, char aRows[9][10]);

int PopulateRows(Board * pBoard);

int PopulateCols(Board * pBoard);

int PopulateSquares(Board * pBoard);

void PrintBoardTileVals(Board stToPrint);

void PrintBoardTiles(Board stToPrint);

void ReduceRow(Row * pRow);

void ReduceCol(Col * pCol);

void ReduceSquare(Square * pSquare);

void ReduceAllRows(Board * pBoard);

void ReduceAllCols(Board * pBoard);

void ReduceAllSquares(Board * pBoard);

int FindUniqueInRow(Row * pRow);

int FindUniqueInCol(Col * pCol);

int FindUniqueInSquare(Square * pSquare);

int FindUniqueInAllRows(Board * pBoard);

int FindUniqueInAllCols(Board * pBoard);

int FindUniqueInAllSquares(Board * pBoard);

int FindValue(Tile * pTile);

int IterateSolution(Board * pBoard);


#endif