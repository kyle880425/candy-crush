#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "func.h"
#include "struc.h"

void free_matrix(int rows, candy **mat){
    int i=0;
    for(i=0;i<rows;i++)
        free(mat[i]);
    free(mat);
}
