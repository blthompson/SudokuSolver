#ifndef __ROW_H__
#define __ROW_H__

#include <stdio.h>

#include "constants.h"
#include "structs.h"

//initializes Row with values
int InitRow (Row * pRow, Tile * aTiles[PUZZLE_SIZE]);

//prints all members
void PrintRow (Row stToPrint);

//prints value
void PrintRowVals (Row stToPrint);



#endif