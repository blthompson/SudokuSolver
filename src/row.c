#include "common.h"
#include "constants.h"
#include "structs.h"
#include "tile.h"
#include "row.h"

int InitRow (Row * pRow, Tile * aTiles[PUZZLE_SIZE]) {
	if(pRow == NULL){
		printf("ERROR: NULL pointer passed to InitRow for pRow\n");
		return -1;
	}

	for(int i = 0; i < PUZZLE_SIZE; i++){
		pRow->aTiles[i] = aTiles[i];
	}

	return 0;
}

void PrintRow (Row stToPrint) {
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

void PrintRowVals (Row stToPrint) {
	for(int i = 0; i < PUZZLE_SIZE; i++){
		if(stToPrint.aTiles[i] != NULL){
			PrintTileVal(*(stToPrint.aTiles[i]));
		} else {
			printf("NULL");
		}
	}
}