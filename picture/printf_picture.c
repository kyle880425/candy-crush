#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "func.h"
#include "struc.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

void printf_picture(candy **A,int rows,int cols,int n,int *score,int *step,int *n_lollipop,int *n_salute,int *n_hand)
{
    // Initialize Allegro
    ALLEGRO_BITMAP *bitmap = NULL;
    ALLEGRO_BITMAP *bitmap1 = NULL;
    ALLEGRO_BITMAP *bitmap2 = NULL;
    ALLEGRO_BITMAP *bitmap3 = NULL;
    ALLEGRO_BITMAP *bitmap4 = NULL;
    ALLEGRO_BITMAP *bitmap5 = NULL;
    ALLEGRO_BITMAP *bitmap6 = NULL;
    ALLEGRO_BITMAP *bitmap7 = NULL;
    ALLEGRO_BITMAP *bitmap8 = NULL;
    ALLEGRO_BITMAP *bitmap9 = NULL;
    ALLEGRO_BITMAP *bitmap10 = NULL;

    ALLEGRO_BITMAP *bitmap11 = NULL;
    ALLEGRO_BITMAP *bitmap12 = NULL;
    ALLEGRO_BITMAP *bitmap13 = NULL;
    ALLEGRO_BITMAP *bitmap14 = NULL;
    ALLEGRO_BITMAP *bitmap15 = NULL;
    ALLEGRO_BITMAP *bitmap16 = NULL;

    ALLEGRO_BITMAP *bitmap21 = NULL;
    ALLEGRO_BITMAP *bitmap22 = NULL;
    ALLEGRO_BITMAP *bitmap23 = NULL;
    ALLEGRO_BITMAP *bitmap24 = NULL;
    ALLEGRO_BITMAP *bitmap25 = NULL;
    ALLEGRO_BITMAP *bitmap26 = NULL;

    ALLEGRO_BITMAP *bitmap31 = NULL;
    ALLEGRO_BITMAP *bitmap32 = NULL;
    ALLEGRO_BITMAP *bitmap33 = NULL;
    ALLEGRO_BITMAP *bitmap34 = NULL;
    ALLEGRO_BITMAP *bitmap35 = NULL;
    ALLEGRO_BITMAP *bitmap36 = NULL;

    ALLEGRO_FONT *pongFont = NULL; /* pointer to Font file */

    al_init_font_addon();    // install font addons
    al_init_ttf_addon();

        bitmap = al_load_bitmap("background.jpg");
        bitmap1 = al_load_bitmap("Red.png");
        bitmap2 = al_load_bitmap("Orange.png");
        bitmap3 = al_load_bitmap("Yellow.png");
        bitmap4 = al_load_bitmap("Green.png");
        bitmap5 = al_load_bitmap("Blue.png");
        bitmap6 = al_load_bitmap("Purple.png");
        bitmap7 = al_load_bitmap("chocolate ball.png");

        bitmap8 = al_load_bitmap("Lollipop.png");
        bitmap9 = al_load_bitmap("Hand.png");
        bitmap10 = al_load_bitmap("Salute.png");

        bitmap11 = al_load_bitmap("b_red.png");
        bitmap12 = al_load_bitmap("b_orange.png");
        bitmap13 = al_load_bitmap("b_yellow.png");
        bitmap14 = al_load_bitmap("b_green.png");
        bitmap15 = al_load_bitmap("b_blue.png");
        bitmap16 = al_load_bitmap("b_purple.png");

        bitmap21 = al_load_bitmap("h_red.png");
        bitmap22 = al_load_bitmap("h_orange.png");
        bitmap23 = al_load_bitmap("h_yellow.png");
        bitmap24 = al_load_bitmap("h_green.png");
        bitmap25 = al_load_bitmap("h_blue.png");
        bitmap26 = al_load_bitmap("h_purple.png");

        bitmap31 = al_load_bitmap("s_red.png");
        bitmap32 = al_load_bitmap("s_orange.png");
        bitmap33 = al_load_bitmap("s_yellow.png");
        bitmap34 = al_load_bitmap("s_green.png");
        bitmap35 = al_load_bitmap("s_blue.png");
        bitmap36 = al_load_bitmap("s_purple.png");


        al_draw_bitmap(bitmap, 0, 0, 0);
        pongFont = al_load_ttf_font("ARCHRISTY.ttf", 60, 0); /* load the FONT file */

        al_draw_textf( pongFont, al_map_rgb(255, 255, 255), 260, 980, -1, "Score: %d",*score);
        al_draw_textf( pongFont, al_map_rgb(255, 255, 255), 660, 980, -1, "Step: %d",*step);
        al_draw_textf( pongFont, al_map_rgb(255, 255, 255), 1128, 518, -1, "X");
        al_draw_textf( pongFont, al_map_rgb(255, 255, 255), 1128, 668, -1, "X");
        al_draw_textf( pongFont, al_map_rgb(255, 255, 255), 1128, 818, -1, "X");
        al_draw_textf( pongFont, al_map_rgb(255, 255, 255), 1168, 518, -1, "%d",*n_lollipop);
        al_draw_textf( pongFont, al_map_rgb(255, 255, 255), 1168, 668, -1, "%d",*n_hand);
        al_draw_textf( pongFont, al_map_rgb(255, 255, 255), 1168, 818, -1, "%d",*n_salute);

        al_draw_bitmap(bitmap8, 998, 508, 0);
        al_draw_bitmap(bitmap9, 998, 658, 0);
        al_draw_bitmap(bitmap10, 998, 808, 0);

        int i,k;
        for(i=0; i<=rows-1; i++)
        {
            for(k=0; k<=cols-1; k++)
            {
                if(A[k][i].color==1&&A[k][i].kind==0)
                {
                    al_draw_bitmap(bitmap1, i*108, k*108, 0);
                }
                if (A[k][i].color==2&&A[k][i].kind==0)
                {
                    al_draw_bitmap(bitmap2, i*108, k*108, 0);
                }
                if (A[k][i].color==3&&A[k][i].kind==0)
                {
                    al_draw_bitmap(bitmap3, i*108, k*108, 0);
                }
                if (A[k][i].color==4&&A[k][i].kind==0)
                {
                    al_draw_bitmap(bitmap4, i*108, k*108, 0);
                }
                if (A[k][i].color==5&&A[k][i].kind==0)
                {
                    al_draw_bitmap(bitmap5, i*108, k*108, 0);
                }
                if (A[k][i].color==6&&A[k][i].kind==0)
                {
                    al_draw_bitmap(bitmap6, i*108, k*108, 0);
                }
                  if (A[k][i].kind==4)
                {
                    al_draw_bitmap(bitmap7, i*108, k*108, 0);
                }
                /*************************************************/
                if(A[k][i].color==1&&A[k][i].kind==1)
                {
                    al_draw_bitmap(bitmap21, i*108, k*108, 0);
                }
                if (A[k][i].color==2&&A[k][i].kind==1)
                {
                    al_draw_bitmap(bitmap22, i*108, k*108, 0);
                }
                if (A[k][i].color==3&&A[k][i].kind==1)
                {
                    al_draw_bitmap(bitmap23, i*108, k*108, 0);
                }
                if (A[k][i].color==4&&A[k][i].kind==1)
                {
                    al_draw_bitmap(bitmap24, i*108, k*108, 0);
                }
                if (A[k][i].color==5&&A[k][i].kind==1)
                {
                    al_draw_bitmap(bitmap25, i*108, k*108, 0);
                }
                if (A[k][i].color==6&&A[k][i].kind==1)
                {
                    al_draw_bitmap(bitmap26, i*108, k*108, 0);
                }
                /*************************************************/
                if(A[k][i].color==1&&A[k][i].kind==2)
                {
                    al_draw_bitmap(bitmap31, i*108, k*108, 0);
                }
                if (A[k][i].color==2&&A[k][i].kind==2)
                {
                    al_draw_bitmap(bitmap32, i*108, k*108, 0);
                }
                if (A[k][i].color==3&&A[k][i].kind==2)
                {
                    al_draw_bitmap(bitmap33, i*108, k*108, 0);
                }
                if (A[k][i].color==4&&A[k][i].kind==2)
                {
                    al_draw_bitmap(bitmap34, i*108, k*108, 0);
                }
                if (A[k][i].color==5&&A[k][i].kind==2)
                {
                    al_draw_bitmap(bitmap35, i*108, k*108, 0);
                }
                if (A[k][i].color==6&&A[k][i].kind==2)
                {
                    al_draw_bitmap(bitmap36, i*108, k*108, 0);
                }
                /*************************************************/
                if(A[k][i].color==1&&A[k][i].kind==3)
                {
                    al_draw_bitmap(bitmap11, i*108, k*108, 0);
                }
                if (A[k][i].color==2&&A[k][i].kind==3)
                {
                    al_draw_bitmap(bitmap12, i*108, k*108, 0);
                }
                if (A[k][i].color==3&&A[k][i].kind==3)
                {
                    al_draw_bitmap(bitmap13, i*108, k*108, 0);
                }
                if (A[k][i].color==4&&A[k][i].kind==3)
                {
                    al_draw_bitmap(bitmap14, i*108, k*108, 0);
                }
                if (A[k][i].color==5&&A[k][i].kind==3)
                {
                    al_draw_bitmap(bitmap15, i*108, k*108, 0);
                }
                if (A[k][i].color==6&&A[k][i].kind==3)
                {
                    al_draw_bitmap(bitmap16, i*108, k*108, 0);
                }
            }
        }

        // Flip display to show the drawing result
        al_flip_display();
       // system("pause");
    if(n==1)
    {
        // Cleanup
        al_destroy_bitmap(bitmap);
        al_destroy_bitmap(bitmap1);
        al_destroy_bitmap(bitmap2);
        al_destroy_bitmap(bitmap3);
        al_destroy_bitmap(bitmap4);
        al_destroy_bitmap(bitmap5);
        al_destroy_bitmap(bitmap6);
        al_destroy_bitmap(bitmap7);
        al_destroy_bitmap(bitmap8);
        al_destroy_bitmap(bitmap9);
        al_destroy_bitmap(bitmap10);

        al_destroy_bitmap(bitmap11);
        al_destroy_bitmap(bitmap12);
        al_destroy_bitmap(bitmap13);
        al_destroy_bitmap(bitmap14);
        al_destroy_bitmap(bitmap15);
        al_destroy_bitmap(bitmap16);

        al_destroy_bitmap(bitmap21);
        al_destroy_bitmap(bitmap22);
        al_destroy_bitmap(bitmap23);
        al_destroy_bitmap(bitmap24);
        al_destroy_bitmap(bitmap25);
        al_destroy_bitmap(bitmap26);

        al_destroy_bitmap(bitmap31);
        al_destroy_bitmap(bitmap32);
        al_destroy_bitmap(bitmap33);
        al_destroy_bitmap(bitmap34);
        al_destroy_bitmap(bitmap35);
        al_destroy_bitmap(bitmap36);

        al_destroy_font( pongFont );
   }
}
