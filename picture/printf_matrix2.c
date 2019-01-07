#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "func.h"
#include "struc.h"

void printf_matrix2(candy **mat,int rows, int cols)
{

  int i=0,j=0;

  for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            printf("%d ",mat[i][j].color);
        }
        printf("\n");
    }

    printf("\n");
}
