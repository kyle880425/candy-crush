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

// Definition of display size

int main()
{



    candy **A;
    int rows, cols;
    int step;
    printf("輸入限制步數:");
    scanf("%d",&step);
    int score=0;

    int n_lollipop=1;//number of lollipop
    int n_salute=1;//number of salute
    int n_hand=1;//number of hand

    printf("design the format of the game\n");
    printf("max of row is 9\n");//因為圖片檔解析度限制
    printf("min of row is 3\n");//檢查的function需求最少要有3個
    printf("row=\n");
    scanf("%d",&rows);
    printf("max of column is 9\n");
    printf("min of column is 3\n");
    printf("column=\n");
    scanf("%d",&cols);

    srand( time(NULL) );

    A = create_matrix2(rows, cols);

    random_mat2D(A, rows, cols);

    // Initialize Allegro
    al_init();
    al_init_image_addon();
    al_init_font_addon();

    // Create allegro display
    ALLEGRO_DISPLAY *display = NULL;
    display = al_create_display(1218,1088);

    printf_picture(A,rows,cols,0,&score,&step,&n_lollipop,&n_salute,&n_hand);
    printf_matrix2(A,rows,cols);

    check_connect(A,rows,cols,&score);
    printf_matrix2(A,rows,cols);
    score=0;
    printf_picture(A,rows,cols,0,&score,&step,&n_lollipop,&n_salute,&n_hand);

    while(step>0){
    MOVE(A,rows,cols,&step,&n_lollipop,&n_salute,&n_hand,&score);
    step=step-1;

    check_connect(A,rows,cols,&score);
    printf_matrix2(A,rows,cols);
    al_rest(0.1);
    printf_picture(A,rows,cols,0,&score,&step,&n_lollipop,&n_salute,&n_hand);
    }

    printf_picture(A,rows,cols,0,&score,&step,&n_lollipop,&n_salute,&n_hand);
    al_destroy_display(display);
    free_matrix(rows,A);

    return 0;
}

