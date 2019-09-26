#ifndef __TILE_H__
#define __TILE_H__

#include <stdio.h>

#include "constants.h"
#include "structs.h"

//allocates new memory for a Tile
int CreateTile(Tile * pTile);

//frees memory for tile
void DestroyTile(Tile * pTile);

//initializes Tile with values
int InitTile(Tile * pTile, int iXPos, int iYPos, Row * pRow, Col * pCol, Square * pSqaure);

//prints all members
void PrintTile (Tile stToPrint);

//prints value
void PrintTileVal (Tile stToPrint);


#endif