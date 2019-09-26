#include "common.h"
#include "constants.h"
#include "structs.h"
#include "tile.h"
#include "col.h"


int InitCol (Col * pCol, Tile * aTiles[PUZZLE_SIZE]) {
	if(pCol == NULL){
		printf("ERROR: NULL pointer passed to InitCol for pCol\n");
		return -1;
	}

	for(int i = 0; i < PUZZLE_SIZE; i++){
		pCol->aTiles[i] = aTiles[i];
	}

	return 0;
}

void PrintCol (Col stToPrint) {
	for(int i = 0; i < PUZZLE_SIZE; i++){
		printf("Tile %d\n", i + 1);

		if(stToPrint.aTiles[i] != NULL){
			PrintTile(*(stToPrint.aTiles[i]));
		} else {
			printf("Tile %d is NULL\n", i);
		}

		
		printf("\n");
	}
}

void PrintColVals (Col stToPrint) {
	for(int i = 0; i < PUZZLE_SIZE; i++){
		if(stToPrint.aTiles[i] != NULL){
			PrintTileVal(*(stToPrint.aTiles[i]));
		} else {
			printf("NULL");
		}
		printf("\n");
	}
}