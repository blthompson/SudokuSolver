#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <stdio.h>

#include "constants.h"
#include "structs.h"

//initializes Row with values
int InitSquare (Square * pSquare, Tile * aTiles[SQRT_SIZE][SQRT_SIZE]);

//prints all members
void PrintSquare (Square stToPrint);

//prints value
void PrintSquareVals (Square stToPrint);



#endif