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
void color_ball_boom(candy **CANDY,int row,int col,int color_ball,int cx,int cy)
{
    int i,j;

        for(i=0; i<row; i++)//兩個for loop去檢查全部的糖果 哪些有跟被彩球碰到的糖果一樣的顏色
        {
            for(j=0; j<col; j++)
            {
                if(CANDY[i][j].color==color_ball)//如果那個CANDY[i][j]的位置的顏色跟被彩球碰到的顏色一樣就消除
                {
                    CANDY[i][j].color=0;//消除
                }
            }
        }
        CANDY[cy][cx].kind=0;
}
