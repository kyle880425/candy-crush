#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>
#include "func.h"
#include "struc.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

candy **hand(candy **c,int rows,int cols,int *n_hand)
{
    ALLEGRO_MOUSE_STATE MSstate;
    al_install_mouse();

    int x=0,y=0;
    int w=0,z=0;

    int xr=1000,yr=1000;
    int wr=1000,zr=1000;

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
            *n_hand=*n_hand+1;
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

    while(w==0 && z==0)
    {
        al_get_mouse_state(&MSstate);
        if(al_mouse_button_down(&MSstate,1))
        {
            w=al_get_mouse_state_axis(&MSstate,0);
            z=al_get_mouse_state_axis(&MSstate,1);
            while(1)
            {
                al_get_mouse_state(&MSstate);
                al_rest(0.01);
                if(al_mouse_button_down(&MSstate,1)==0)
                {
                    wr=al_get_mouse_state_axis(&MSstate,0);
                    zr=al_get_mouse_state_axis(&MSstate,1);
                    break;
                }
            }

        }

        if(w>972||z>972)
        {
            *n_hand=*n_hand+1;
            return c;
        }

        if( ((int)w/108) == ((int)wr/108) && ((int)z/108) == ((int)zr/108))
        {
            break;
        }
        else
        {
            w=0;
            z=0;
        }
    }

    printf("x=%d y=%d\n",x,y);
    printf("w=%d z=%d\n",w,z);

    x=(int) x/108;
    y=(int) y/108;
    w=(int) w/108;
    z=(int) z/108;

    candy e;

    e=c[y][x];
    c[y][x]=c[z][w];
    c[z][w]=e;

    check_specialcandy(c,rows,cols,x,y);
    check_specialcandy(c,rows,cols,w,z);
    return c;
}
