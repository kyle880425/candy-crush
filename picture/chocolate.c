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

        for(i=0; i<row; i++)//���for loop�h�ˬd�������}�G ���Ǧ���Q�m�y�I�쪺�}�G�@�˪��C��
        {
            for(j=0; j<col; j++)
            {
                if(CANDY[i][j].color==color_ball)//�p�G����CANDY[i][j]����m���C���Q�m�y�I�쪺�C��@�˴N����
                {
                    CANDY[i][j].color=0;//����
                }
            }
        }
        CANDY[cy][cx].kind=0;
}
