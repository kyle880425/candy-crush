#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>
#include "func.h"
#include "struc.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5\allegro_primitives.h>

candy **lollipop(candy **c,int rows,int cols,int *n_lollipop,int *score)
{
    ALLEGRO_MOUSE_STATE MSstate;
    al_install_mouse();

    int x=0,y=0;

    int xr=1000,yr=1000;

    while(x==0 && y==0)
    {
        al_get_mouse_state(&MSstate);
        if(al_mouse_button_down(&MSstate,1))
        {
            x=al_get_mouse_state_axis(&MSstate,0);
            y=al_get_mouse_state_axis(&MSstate,1);
            while(1)
            {
                al_get_mouse_state(&MSstate);
                al_rest(0.01);
                if(al_mouse_button_down(&MSstate,1)==0)
                {
                    xr=al_get_mouse_state_axis(&MSstate,0);
                    yr=al_get_mouse_state_axis(&MSstate,1);
                    break;
                }
            }

        }

        if(x>972||y>972)
        {
            *n_lollipop=*n_lollipop+1;
            return c;
        }

        if( ((int)x/108) == ((int)xr/108) && ((int)y/108) == ((int)yr/108))
        {
            break;
        }
        else
        {
            x=0;
            y=0;
        }
    }

    printf("x=%d y=%d\n",x,y);

    x=(int) x/108;
    y=(int) y/108;

    c[y][x].color=0;
    c[y][x].kind=0;
    c[y][x].clear_enable=1;
    *score=*score+1;//­p¤À

    fall(c,rows,cols);
    check_specialcandy(c,rows,cols,x,y);
    check_connect(c,rows,cols,score);

    return c;
}
