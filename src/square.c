#include "common.h"
#include "constants.h"
#include "structs.h"
#include "tile.h"
#include "square.h"


int InitSquare (Square * pSquare, Tile * aTiles[SQRT_SIZE][SQRT_SIZE]) {
	if(pSquare == NULL){
		printf("ERROR: NULL pointer passed to InitRow for pSqure\n");
		return -1;
	}

	for(int i = 0; i < SQRT_SIZE; i++){
		for(int j = 0; j < SQRT_SIZE; j++){
			pSquare->aTiles[i][j] = aTiles[i][j];
		}
	}

	return 0;
}

void PrintSquare(Square stToPrint) {
	for(int i = 0; i < SQRT_SIZE; i++){
		for (int j = 0; j < SQRT_SIZE; j++){
			printf("Tile %d, %d\n", i + 1, j + 1);

			if(stToPrint.aTiles[i][j] != NULL){
				PrintTile(*(stToPrint.aTiles[i][j]));
			} else {
				printf("Tile %d, %d is NULL\n", i, j);
			}
		}
		
		printf("\n");
	}
}

void PrintSquareVals(Square stToPrint) {
	for(int i = 0; i < SQRT_SIZE; i++){
		for(int j = 0; j < SQRT_SIZE; j++){
			if(stToPrint.aTiles[i][j] != NULL){
			PrintTileVal(*(stToPrint.aTiles[i][j]));
			} else {
				printf("NULL");
			}
		}
		
		printf("\n");
	}
}