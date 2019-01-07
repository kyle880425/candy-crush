
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "func.h"
#include "struc.h"
candy **create_matrix2(int rows, int cols)
{
// input rows and cols
// output a pointer to 2D mat[rows][cols]

    candy **mat = (candy **) malloc(sizeof(candy*)*rows);
    int i=0,j=0;
    for(i=0; i<rows; i++)
        // Allocate array, store pointer
        mat[i] = (candy *) malloc(sizeof(candy)*cols);

    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            mat[i][j].color=0;
            mat[i][j].kind=0;
        }
    }
    return mat;
}
