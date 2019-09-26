#include "common.h"
#include "constants.h"
#include "structs.h"
#include "tile.h"

int CreateTile(Tile * pTile) {
	int iRet;
	pTile = malloc(sizeof(Tile));

	if(pTile == NULL){
		printf("ERROR: Failed to allocate memory for tile\n");
		return -1;
	}

	iRet = InitTile(pTile, -1, -1, NULL, NULL, NULL);
	if(iRet != 0){
		printf("Failed to rule InitTile in CreateTile\n");
		free(pTile);
		return -1;
	}

	return 0;
}

void DestroyTile(Tile * pTile) {
	free(pTile);
}

int InitTile(Tile * pTile, int iXPos, int iYPos, Row * pRow, Col * pCol, Square * pSqaure) {
	if(pTile == NULL){
		printf("ERROR: NULL pointer passed to InitTile for pTile\n");
		return -1;
	}

	pTile->iValue = -1;
	pTile->iXPos = iXPos;
	pTile->iYPos = iYPos;
	pTile->pRow = pRow;
	pTile->pCol = pCol;
	pTile->pSquare = pSqaure;

	for (int i = 0; i < PUZZLE_SIZE; i++) {
		pTile->iPossibleVals[i] = 1;
	}

	return 0;
}

void PrintTile(Tile stToPrint) {
	printf("Value: %d\n", stToPrint.iValue);
	printf("X Position: %d\n", stToPrint.iXPos);
	printf("Y Position: %d\n", stToPrint.iYPos);
	printf("Possible Values: ");

	for (int i = 0; i < PUZZLE_SIZE; i++) {
		if(stToPrint.iPossibleVals[i] != 0) {
			printf("%d", stToPrint.iPossibleVals[i]);
		}
	}
	printf("\n");
}

void PrintTileVal(Tile stToPrint) {
	if(stToPrint.iValue != -1){
		printf("%d", stToPrint.iValue);
	} else {
		printf("_");
	}
}
