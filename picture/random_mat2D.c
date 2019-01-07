
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "func.h"
#include "struc.h"

void random_mat2D(candy **a, int rows, int cols)
{
    // randomize all elements in a

    int i=0,j=0;

    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            a[i][j].color=rand()%6+1;
            a[i][j].kind=0;
            a[i][j].clear_enable=1;
        }
    }
}
