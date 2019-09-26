#ifndef __COL_H__
#define __COL_H__

#include <stdio.h>

#include "constants.h"
#include "structs.h"

//initializes Row with values
int InitCol (Col * pRow, Tile * aTiles[PUZZLE_SIZE]);

//prints all members
void PrintCol (Col stToPrint);

//prints value
void PrintColVals (Col stToPrint);



#endif