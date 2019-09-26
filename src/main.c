#include "common.h"
#include "constants.h"
#include "structs.h"
#include "tile.h"
#include "row.h"
#include "col.h"
#include "square.h"
#include "solver.h"

int main()
{
   char rows[9][10];
   strcpy(rows[0], "7-9----4-");
   strcpy(rows[1], "1-----5--");
   strcpy(rows[2], "--214-378");
   strcpy(rows[3], "----9381-");
   strcpy(rows[4], "-5-6-1-9-");
   strcpy(rows[5], "-9148----");
   strcpy(rows[6], "315-672--");
   strcpy(rows[7], "--8-----7");
   strcpy(rows[8], "-4----9-3");


   SolvePuzzle(rows);

   return 0;
}