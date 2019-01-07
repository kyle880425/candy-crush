#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>
#include "func.h"
#include "struc.h"


#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

void boom(candy **A,int rows,int cols){
    int i=0,k=0;
    for(i=0; i<=rows-1; i++)
        {
            for(k=0; k<=cols-1; k++)
            {
                if(A[i][k].color==0 && A[i][k].kind!=0){
                    switch(A[i][k].kind){
                    case 1:
                        stripe_row_boom(A,rows,cols,k,i);
                        break;
                    case 2:
                        stripe_column_boom(A,rows,cols,k,i);
                        break;
                    case 3:
                        bag_candy_boom(A,rows,cols,k,i);
                        break;
                    case 4:
                        color_ball_boom(A,rows,cols,rand()%6,k,i);
                        break;


                    }
                }
            }
        }
}
