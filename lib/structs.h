#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include "constants.h"

typedef struct tile Tile;
typedef struct row Row;
typedef struct col Col;
typedef struct square Square;
typedef struct board Board;

//value is -1 if unsolved
struct tile{
	int iValue;
	int iXPos;
	int iYPos;
	Row * pRow;
	Col * pCol;
	Square * pSquare;
	int aPossibleVals[PUZZLE_SIZE];		//0 is index + 1 is NOT possible
};

struct row{
	Tile * aTiles[PUZZLE_SIZE];
};

struct col{
	Tile * aTiles[PUZZLE_SIZE];
};

struct square{
	Tile * aTiles[SQRT_SIZE][SQRT_SIZE];
};

struct board{
	Tile aTiles[PUZZLE_SIZE][PUZZLE_SIZE];
	Row aRows[PUZZLE_SIZE];
	Col aCols[PUZZLE_SIZE];
	Square aSquares [SQRT_SIZE][SQRT_SIZE];
};

#endif