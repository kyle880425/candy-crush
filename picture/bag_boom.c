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
void bag_candy_boom(candy **CANDY,int row,int col,int bx,int by)
{
    int i=by,j=bx;

    if(i==0)
    {
        CANDY[i][j-1].color=0;
        CANDY[i][j].color=0;
        CANDY[i][j+1].color=0;
        CANDY[i+1][j-1].color=0;
        CANDY[i+1][j].color=0;
        CANDY[i+1][j+1].color=0;
    }

    if(i==8)
    {
        CANDY[i-1][j-1].color=0;
        CANDY[i-1][j].color=0;
        CANDY[i-1][j+1].color=0;
        CANDY[i][j-1].color=0;
        CANDY[i][j].color=0;
        CANDY[i][j+1].color=0;
    }

    if(j==0)
    {
        CANDY[i-1][j].color=0;
        CANDY[i-1][j+1].color=0;
        CANDY[i][j].color=0;
        CANDY[i][j+1].color=0;
        CANDY[i+1][j].color=0;
        CANDY[i+1][j+1].color=0;
    }

    if(j==8)
    {
        CANDY[i-1][j-1].color=0;
        CANDY[i-1][j].color=0;
        CANDY[i][j-1].color=0;
        CANDY[i][j].color=0;
        CANDY[i+1][j-1].color=0;
        CANDY[i+1][j].color=0;

    }
    else
    {
        CANDY[i-1][j-1].color=0;
        CANDY[i-1][j].color=0;
        CANDY[i-1][j+1].color=0;
        CANDY[i][j-1].color=0;
        CANDY[i][j].color=0;
        CANDY[i][j+1].color=0;
        CANDY[i+1][j-1].color=0;
        CANDY[i+1][j].color=0;
        CANDY[i+1][j+1].color=0;
    }
    CANDY[by][bx].kind=0;
}
