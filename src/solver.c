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
	printf("\n");

	while(1){
		int iChanges = IterateSolution(&stBoard);

		if(iChanges == 0){
			break;
		}
			
	}

	printf("Solved:\n\n");
	PrintBoardTileVals(stBoard);

	return 0;
}

int PopulateTiles(Board * pBoard, char aRows[PUZZLE_SIZE][PUZZLE_SIZE + 1]){
	for(int i = 0; i < PUZZLE_SIZE; i++){
		for(int j = 0; j < PUZZLE_SIZE; j++){
			InitTile(&(pBoard->aTiles[i][j]), i, j, NULL, NULL, NULL);
			if((aRows[i][j] >= '0' && aRows[i][j] <= PUZZLE_SIZE + '0') || aRows[i][j] == '-') {
				if(aRows[i][j] != '-'){
					pBoard->aTiles[i][j].iValue = aRows[i][j] - '0';

					for(int k = 0; k < PUZZLE_SIZE; k++){
						if(aRows[i][j] - '0' != k + 1){
							pBoard->aTiles[i][j].aPossibleVals[k] = 0;
						}
					}
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

void PrintBoardTiles(Board stToPrint){
	for(int i = 0; i < PUZZLE_SIZE; i++){
		for(int j = 0; j < PUZZLE_SIZE; j++){
			PrintTile(stToPrint.aTiles[i][j]);
			printf("\n");
		}
		
	}
}

void  ReduceRow(Row * pRow) {
	//Find solved values
	for(int i = 0; i < PUZZLE_SIZE; i++){
		if(pRow->aTiles[i]->iValue != -1){

			for(int j = 0; j < PUZZLE_SIZE; j++){

				if(i != j && pRow->aTiles[j]->iValue == -1){

					pRow->aTiles[j]->aPossibleVals[pRow->aTiles[i]->iValue - 1] = 0;
				}
			}
		}
	}
}

void ReduceCol(Col * pCol) {

	for(int i = 0; i < PUZZLE_SIZE; i++){
		if(pCol->aTiles[i]->iValue != -1){

			for(int j = 0; j < PUZZLE_SIZE; j++){

				if(i != j && pCol->aTiles[j]->iValue == -1){

					pCol->aTiles[j]->aPossibleVals[pCol->aTiles[i]->iValue - 1] = 0;
				}
			}
		}
	}
}

void  ReduceSquare(Square * pSquare) {

	for(int i = 0; i < SQRT_SIZE; i++){
		for(int j = 0; j < SQRT_SIZE; j++){

			if(pSquare->aTiles[i][j]->iValue != -1){

				for(int x = 0; x < SQRT_SIZE; x++){
					for(int y = 0; y < SQRT_SIZE; y++){

						if(i != x && j != y && pSquare->aTiles[x][y]->iValue == -1){
							pSquare->aTiles[x][y]->aPossibleVals[pSquare->aTiles[i][j]->iValue - 1] = 0;

						}
					}
				}
			}
		}
	}
}

void  ReduceAllRows(Board * pBoard){

	for(int i = 0; i < PUZZLE_SIZE; i++){
		ReduceRow(&(pBoard->aRows[i]));
	}

}

void  ReduceAllCols(Board * pBoard){

	for(int i = 0; i < PUZZLE_SIZE; i++){
		ReduceCol(&(pBoard->aCols[i]));
	}
}

void  ReduceAllSquares(Board * pBoard){

	for(int i = 0; i < SQRT_SIZE; i++){
		for(int j = 0; j < SQRT_SIZE; j++){

			ReduceSquare(&(pBoard->aSquares[i][j]));
		}
	}
}

int FindUniqueInRow(Row * pRow){
	int iChanges = 0;

	int aSolvedVals[PUZZLE_SIZE];

	for(int i = 0; i < PUZZLE_SIZE; i++){
		aSolvedVals[i] = 0;
	}

	for(int i = 0; i < PUZZLE_SIZE; i++){
		if(pRow->aTiles[i]->iValue != -1){
			aSolvedVals[pRow->aTiles[i]->iValue - 1] = 1;
		}
	}

	for(int i = 0; i < PUZZLE_SIZE; i++){	//iterate through possible value
		int iNumVals = 0;
		int iValIndex;

		if(aSolvedVals[i] != 1){

			for(int j = 0; j < PUZZLE_SIZE; j++){	//look at at each tile and see how many can have that value

				if(pRow->aTiles[j]->aPossibleVals[i] == 1){
					iNumVals++;
					iValIndex = j;
				}

			}

			if(iNumVals == 1){	//if only one
				pRow->aTiles[iValIndex]->iValue = i + 1;

				for(int j = 0; j < PUZZLE_SIZE; j++){
					if(j != iValIndex){
						pRow->aTiles[j]->aPossibleVals[i] = 0;
					}

					if(j != i){
						pRow->aTiles[iValIndex]->aPossibleVals[j] = 0;
					}
				}
				iChanges++;
			}
		}
	}
	return iChanges;
}

int FindUniqueInCol(Col * pCol){
	int iChanges = 0;
	int aSolvedVals[PUZZLE_SIZE];

	for(int i = 0; i < PUZZLE_SIZE; i++){
		aSolvedVals[i] = 0;
	}

	for(int i = 0; i < PUZZLE_SIZE; i++){
		if(pCol->aTiles[i]->iValue != -1){
			aSolvedVals[pCol->aTiles[i]->iValue - 1] = 1;
		}
	}

	for(int i = 0; i < PUZZLE_SIZE; i++){
		int iNumVals = 0;
		int iValIndex;

		if(aSolvedVals[i] != 1){

			for(int j = 0; j < PUZZLE_SIZE; j++){

				if(pCol->aTiles[j]->aPossibleVals[i] == 1){
					iNumVals++;
					iValIndex = j;
				}

			}

			if(iNumVals == 1){
				pCol->aTiles[iValIndex]->iValue = i + 1;

				for(int j = 0; j < PUZZLE_SIZE; j++){
					if(j != iValIndex){
						pCol->aTiles[j]->aPossibleVals[i] = 0;
					}

					if(j != i){
						pCol->aTiles[iValIndex]->aPossibleVals[j] = 0;
					}
				}
				iChanges++;
			}
		}
	}

	return iChanges;
}

int FindUniqueInSquare(Square * pSquare){
	int iChanges = 0;
	int aSolvedVals[PUZZLE_SIZE];

	for(int i = 0; i < PUZZLE_SIZE; i++){
		aSolvedVals[i] = 0;
	}

	for(int i = 0; i < PUZZLE_SIZE; i++){
		for(int j = 0; j < PUZZLE_SIZE; j++){
			if(pSquare->aTiles[i][j]->iValue != -1){
				aSolvedVals[pSquare->aTiles[i][j]->iValue - 1] = 1;
			}
		}
	}


	for(int i = 0; i < PUZZLE_SIZE; i++){

		int iNumVals = 0;
		int iValIndexOne;
		int iValIndexTwo;

		if(aSolvedVals[i] != 1){

			for(int x = 0; x < SQRT_SIZE; x++){
				for(int y = 0; y < SQRT_SIZE; y++){

					if(pSquare->aTiles[x][y]->aPossibleVals[i] == 1){
						iNumVals++;
						iValIndexOne = x;
						iValIndexTwo = y;
					}

				}
			}

			if(iNumVals == 1){
				pSquare->aTiles[iValIndexOne][iValIndexTwo]->iValue = i + 1;

				for(int x = 0; x < SQRT_SIZE; x++){
					for(int y = 0; y < SQRT_SIZE; y++){
						if(x != iValIndexOne && y != iValIndexTwo){
							pSquare->aTiles[x][y]->aPossibleVals[i] = 0;
						}
					}
				}

				for(int j = 0; j < PUZZLE_SIZE; j++){
					if(j != i){
						pSquare->aTiles[iValIndexOne][iValIndexTwo]->aPossibleVals[j] = 0;
					}
				}
				iChanges++;
			}
		}
	}

	return iChanges;
}

int FindUniqueInAllRows(Board * pBoard){
	int iChanges = 0;

	for(int i = 0; i < PUZZLE_SIZE; i++){
		iChanges += FindUniqueInRow(&(pBoard->aRows[i]));
	}

	return iChanges;
}

int FindUniqueInAllCols(Board * pBoard){
	int iChanges = 0;

	for(int i = 0; i < PUZZLE_SIZE; i++){
		iChanges += FindUniqueInCol(&(pBoard->aCols[i]));
	}

	return iChanges;
}

int FindUniqueInAllSquares(Board * pBoard){
	int iChanges = 0;

	for(int i = 0; i < SQRT_SIZE; i++){
		for(int j = 0; j < SQRT_SIZE; j++){
			iChanges += FindUniqueInSquare(&(pBoard->aSquares[i][j]));
		}
	}


	return iChanges;
}

int FindValue(Tile * pTile){

	int iNumPossibles = 0;
	int iPossibleVal;

	for(int i = 0; i < PUZZLE_SIZE; i++){
		if(pTile->aPossibleVals[i] != 0){
			iPossibleVal = i + 1;
			iNumPossibles++;
		}
	}

	if(iNumPossibles == 1 && pTile->iValue == -1){
		return iPossibleVal;
	}

	return -1;
}

int IterateSolution(Board * pBoard){

	int iChanges = 0;

	ReduceAllRows(pBoard);
	ReduceAllCols(pBoard);
	ReduceAllSquares(pBoard);

	for(int i = 0; i < PUZZLE_SIZE; i++){
		for(int j = 0; j < PUZZLE_SIZE; j++){

			if(pBoard->aTiles[i][j].iValue == -1){
				int iNewVal = FindValue(&(pBoard->aTiles[i][j]));

				if (iNewVal != -1){
					iChanges++;
					pBoard->aTiles[i][j].iValue = iNewVal;
				}
			}

		}
	}

	iChanges += FindUniqueInAllRows(pBoard);
	iChanges += FindUniqueInAllRows(pBoard);
	iChanges += FindUniqueInAllRows(pBoard);

	return iChanges;
}