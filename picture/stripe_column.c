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
void stripe_column_boom(candy **CANDY,int row,int col,int sx,int sy)
{
    int j;

        for(j=0; j<col; j++)//�}�G��m�w�g�Q�x�s   �ҥH��w����i�T�w   ��j   ��j���P��
        {
            CANDY[j][sx].color=0;
        }
        CANDY[sy][sx].kind=0;

}

