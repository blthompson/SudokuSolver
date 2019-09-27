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
   strcpy(rows[0], "1---4-26-");
   strcpy(rows[1], "8-31-6---");
   strcpy(rows[2], "9-----3-1");
   strcpy(rows[3], "78--34-5-");
   strcpy(rows[4], "4--7-9--2");
   strcpy(rows[5], "-9-81--37");
   strcpy(rows[6], "5-4-----3");
   strcpy(rows[7], "---4-16-9");
   strcpy(rows[8], "-69-8---4");


   SolvePuzzle(rows);

   return 0;
}