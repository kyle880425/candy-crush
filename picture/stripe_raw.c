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
void stripe_row_boom(candy **CANDY,int row,int col,int sx,int sy)
{
    int i;

        for(i=0; i<row; i++)//糖果位置已經被儲存   所以把已知的j固定   動i   把i全部銷掉
        {
            CANDY[sy][i].color=0;
        }
        CANDY[sy][sx].kind=0;
}

