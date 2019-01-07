#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>
#include "func.h"
#include "struc.h"

candy **salute(candy **c,int rows,int cols)
{
    int i,k;

    for(i=0; i<=rows-1; i++)
    {
        for(k=0; k<=cols-1; k++)
        {
            c[i][k].color=0;
            c[i][k].kind=0;
            c[i][k].clear_enable=1;

        }
    }

    return c;
}
