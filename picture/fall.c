
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "func.h"
#include "struc.h"

candy **fall(candy **A,int rows,int cols)
{
    int i=0,j=0,check_0=0;

    while(check_0<(rows-1))
    {
        for(i=0; i< rows-1; i++)
        {
            for(j=0; j<cols; j++)
            {
                if(A[i][j].color>0 && A[i+1][j].color==0)
                {
                    A[i+1][j]=A[i][j];
                    A[i][j].color=0;
                    A[i][j].kind=0;
                    A[i][j].clear_enable=1;
                }
            }
        }
        check_0=check_0+1;
    }
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            if(A[i][j].color==0)
            {
                A[i][j].color=rand()%6+1;
                A[i][j].kind=0;
                A[i][j].clear_enable=1;
            }
        }
    }
    return A;
}
