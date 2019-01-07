#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>
#include "func.h"
#include "struc.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

candy **MOVE(candy **c,int rows,int cols,int *step,int *n_lollipop,int *n_salute,int *n_hand,int *score)
{


    ALLEGRO_MOUSE_STATE MSstate;
    al_install_mouse();


    int j=0;



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

        if(*n_hand>0)
        {
            if(x>=998&&y>=650&&x<=1087&&y<=731)
            {
                c=hand(c,rows,cols,n_hand);
                *step=*step+1;
                *n_hand=*n_hand-1;

                return c;
            }
        }

        if(*n_lollipop>0)
        {
            if(x>=998&&y>=506&&x<=1087&&y<=591)
            {
                c=lollipop(c,rows,cols,n_lollipop,score);
                *step=*step+1;
                *n_lollipop=*n_lollipop-1;

                return c;
            }
        }

        if(*n_salute>0)
        {
            if(x>=998&&y>=800&&x<=1087&&y<=881)
            {
                c=salute(c,rows,cols);
                *step=*step+1;
                *n_salute=*n_salute-1;

                return c;
            }
        }
        if(x>972||y>972)
        {
            x=y=1000;
            xr=yr=0;
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

    int f;
    double g;
    g=sqrt((w-x)*(w-x)+(z-y)*(z-y));
    if(g>1)//確定只能移動附近
    {
        printf("x=%d \n",abs(w-x));
        printf("w=%d \n",abs(z-y));
        f=0;
    }

    candy e;

    e=c[y][x];
    c[y][x]=c[z][w];
    c[z][w]=e;

    int i,k;
    int d=0;

    for(i=0; i<=rows-1; i++)
    {
        for(k=0; k<=cols-3; k++)
        {
            if(c[i][k].color == c[i][k+1].color && c[i][k].color== c[i][k+2].color)
            {
                d=1;
            }
            else
            {
                d=0;
            }
            if(d==1)
            {
                break;
            }
        }
        if(d==1)
        {
            break;
        }
    }

    if(d==0)
    {
        for(i=0; i<=rows-3; i++)
        {
            for(k=0; k<=cols-1; k++)
            {
                if(c[i][k].color == c[i+1][k].color && c[i+1][k].color == c[i+2][k].color)
                {
                    d=1;
                }
                else
                {
                    d=0;
                }
                if(d==1)
                {
                    break;
                }
            }
            if(d==1)
            {
                break;
            }
        }
    }

    /*if(c[y][x].kind==4 || c[z][w].kind==4){
        if(c[y][x].kind==4 && c[z][w].kind!=4){
            color_ball_boom(c,rows,cols,c[z][w].color,y,x);
        }
        else if(c[y][x].kind!=4 && c[z][w].kind==4){
            color_ball_boom(c,rows,cols,c[y][x].color,z,w);
        }
        else{
            for(i=0; i<=rows-1; i++)
            {
                for(j=0; j<=cols-1; j++)
                {
                    c[i][j].color=0;
                }
            }
        }
    }*/

    if(d==0||f==0)
    {
        e=c[y][x];
        c[y][x]=c[z][w];
        c[z][w]=e;
        printf("Nothing happened in this step\n");
        *step=*step+1;
    }
    else{
        check_specialcandy(c,rows,cols,x,y);
        check_specialcandy(c,rows,cols,w,z);
    }

    return c;
}

