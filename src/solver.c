#include "common.h"
#include "constants.h"
#include "structs.h"
#include "tile.h"
#include "row.h"
#include "col.h"
#include "square.h"
#include "solver.h"

int SolvePuzzle(char aRows[PUZZLE_SIZE][PUZZLE_SIZE + 1]){
	int iRet;
	Board stBoard;

	iRet = PopulateTiles(&stBoard, aRows);
	if(iRet != 0){
		printf("ERROR: could not populate board tiles\n");
		return -1;
	}

	iRet = PopulateRows(&stBoard);
	if(iRet != 0){
		printf("ERROR: could not populate board rows\n");
		return -1;
	}

	iRet = PopulateCols(&stBoard);
	if(iRet != 0){
		printf("ERROR: could not populate board cols\n");
		return -1;
	}

	iRet = PopulateSquares(&stBoard);
	if(iRet != 0){
		printf("ERROR: could not populate board squares\n");
		return -1;
	}

	PrintBoardTileVals(stBoard);
	printf("\n");
	PrintBoardRowVals(stBoard);
	printf("\n");
	PrintBoardColVals(stBoard);
	printf("\n");
	PrintBoardSquareVals(stBoard);
	printf("\n");
	TestPrint(stBoard);


	return 0;
}

int PopulateTiles(Board * pBoard, char aRows[PUZZLE_SIZE][PUZZLE_SIZE + 1]){
	for(int i = 0; i < PUZZLE_SIZE; i++){
		for(int j = 0; j < PUZZLE_SIZE; j++){
			InitTile(&(pBoard->aTiles[i][j]), i, j, NULL, NULL, NULL);
			if((aRows[i][j] >= '0' && aRows[i][j] <= PUZZLE_SIZE + '0') || aRows[i][j] == '-') {
				if(aRows[i][j] != '-'){
					pBoard->aTiles[i][j].iValue = aRows[i][j] - '0';
				}
			} else {
				printf("ERROR: invalid char in board file\n");
				return -1;
			}
		}
	}


	return 0;
}

int PopulateRows(Board * pBoard){
	for(int i = 0; i < PUZZLE_SIZE; i++){
		for(int j = 0; j < PUZZLE_SIZE; j++){
			(pBoard->aRows[i]).aTiles[j] = &(pBoard->aTiles[i][j]);
			pBoard->aTiles[i][j].pRow = &(pBoard->aRows[i]);
		}
	}

	return 0;
}

int PopulateCols(Board * pBoard){
	for(int i = 0; i < PUZZLE_SIZE; i++){
		for(int j = 0; j < PUZZLE_SIZE; j++){
			(pBoard->aCols[j]).aTiles[i] = &(pBoard->aTiles[i][j]);
			pBoard->aTiles[i][j].pCol = &(pBoard->aCols[j]);
		}
	}
	return 0;
}

int PopulateSquares(Board * pBoard){
	
	for(int i = 0; i < PUZZLE_SIZE; i++){
		for(int j = 0; j < PUZZLE_SIZE; j++){
			(pBoard->aSquares[i / SQRT_SIZE][j / SQRT_SIZE]).aTiles[i % SQRT_SIZE][j % SQRT_SIZE] = &(pBoard->aTiles[i][j]);
			pBoard->aTiles[i][j].pSquare = &(pBoard->aSquares[i / SQRT_SIZE][j / SQRT_SIZE]);
		}
	}

	return 0;
}

void PrintBoardTileVals(Board stToPrint){

	for(int i = 0; i < PUZZLE_SIZE; i++){
		for(int j = 0; j < PUZZLE_SIZE; j++){
			PrintTileVal(stToPrint.aTiles[i][j]);
		}
		printf("\n");
	}
}
