
#ifndef _FUNCTION_HEADER_H_
#define _FUNCTION_HEADER_H_

#include "struc.h"
candy **create_matrix2(int rows, int cols);
void printf_picture(candy **A,int rows,int cols,int n,int *score,int *step,int *n_lollipop,int *n_salute,int *n_hand);
void random_mat2D(candy **a, int rows, int cols);
candy **fall(candy **A,int rows,int cols);
candy **check_connect(candy **A, int rows, int cols,int *score);
void printf_matrix2(candy **matint,int rows, int cols);
candy **MOVE(candy **c,int rows,int cols,int *step,int *lollipop,int *salute,int *hand,int *score);
void free_matrix(int rows, candy **mat);
int check_specialcandy(candy **A,int rows,int cols,int movex,int movey);
void color_ball_boom(candy **CANDY,int row,int col,int color_ball,int cx,int cy);
void stripe_column_boom(candy **CANDY,int row,int col,int sx,int sy);
void stripe_row_boom(candy **CANDY,int row,int col,int sx,int sy);
candy **hand(candy **c,int rows,int cols,int *n_hand);
candy **lollipop(candy **c,int rows,int cols,int *n_lollipop,int *score);
candy **salute(candy **c,int rows,int cols);
void bag_candy_boom(candy **CANDY,int row,int col,int bx,int by);
void boom(candy **A,int rows,int cols);
#endif // _FUNCTION_HEADER_H_
