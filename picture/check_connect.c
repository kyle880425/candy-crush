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

candy **check_connect(candy **A, int rows, int cols,int *score)
{

    int n=1;
    candy **b=create_matrix2(rows,cols);
    int i,k,j,l=0,m=0;

    /****************************移動後的第一梯次消除************************/
    for(i=0; i<=rows-1; i++)
        {
            for(k=0; k<=cols-1; k++)
            {
                b[i][k].color=0;
            }
        }
        for(i=0; i<=rows-3; i++)//檢查直排
        {
            for(k=0; k<=cols-1; k++)//最多找到倒數第三個
            {
                if(A[i][k].color==A[i+1][k].color && A[i+2][k].color==A[i][k].color)//確定有三個相連
                {
                    l=3;
                    for(j=i+3; j<=rows-1; j++)//確定接下來還有沒有相連
                    {
                        if(A[i][k].color==A[j][k].color)
                        {
                            l=l+1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                for(m=0; m<l; m++)//紀錄連續糖果的位置
                {
                    b[i+m][k].color=1;
                }
                l=0;
            }
        }

        for(i=0; i<=rows-1; i++)//檢查橫排
        {
            for(k=0; k<=cols-3; k++)
            {
                if(A[i][k].color==A[i][k+1].color && A[i][k].color==A[i][k+2].color)
                {
                    l=3;
                    for(j=k+3; j<=cols-1; j++)
                    {
                        if(A[i][k].color==A[i][j].color)
                        {
                            l=l+1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                for(m=0; m<l; m++)
                {
                    b[i][k+m].color=1;
                }
                l=0;
            }
        }

        /**************************計分&計分***************************/
        for(i=0; i<=rows-1; i++)
        {
            for(k=0; k<=cols-1; k++)
            {
                if(b[i][k].color==1 && A[i][k].clear_enable==1)
                {
                    A[i][k].color=0;
                    boom(A,rows,cols);
                    *score=*score+1;//計分
                }

                if(A[i][k].clear_enable==0)
                {

                    *score=*score+1;//計分
                }
            }
        }
        /**********************************************************/
        for(i=0; i<=rows-1; i++)
        {
            for(k=0; k<=cols-1; k++)
            {
                if(b[i][k].color==1)
                {
                    n=1;
                    break;//確定還有沒有需要消除的
                }
                if(b[i][k].color==0)
                {
                    n=0;
                }
            }
            if(n==1)
            {
                break;
            }
        }
        fall(A,rows,cols);

        //第一梯次消除完成

        for(i=0; i<=rows-1; i++)
        {
            for(k=0; k<=cols-1; k++)
            {
                A[i][k].clear_enable=1;//將clear_enable都變為1
            }
        }


    /*************************************************************************/
    /*********************************天降************************************/
    /*************************************************************************/

    while(n==1)
    {
        for(i=0; i<=rows-1; i++)
        {
            for(k=0; k<=cols-1; k++)
            {
                b[i][k].color=0;
            }
        }
        for(i=0; i<=rows-3; i++)//檢查直排
        {
            for(k=0; k<=cols-1; k++)//最多找到倒數第三個
            {
                if(A[i][k].color==A[i+1][k].color && A[i+2][k].color==A[i][k].color)//確定有三個相連
                {
                    l=3;
                    for(j=i+3; j<=rows-1; j++)//確定接下來還有沒有相連
                    {
                        if(A[i][k].color==A[j][k].color)
                        {
                            l=l+1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                for(m=0; m<l; m++)//紀錄連續糖果的位置
                {
                    b[i+m][k].color=1;
                }
                l=0;
            }
        }

        for(i=0; i<=rows-1; i++)//檢查橫排
        {
            for(k=0; k<=cols-3; k++)
            {
                if(A[i][k].color==A[i][k+1].color && A[i][k].color==A[i][k+2].color)
                {
                    l=3;
                    for(j=k+3; j<=cols-1; j++)
                    {
                        if(A[i][k].color==A[i][j].color)
                        {
                            l=l+1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                for(m=0; m<l; m++)
                {
                    b[i][k+m].color=1;
                }
                l=0;
            }
        }

        /**************************計分&計分***************************/
        for(i=0; i<=rows-1; i++)
        {
            for(k=0; k<=cols-1; k++)
            {
                if(b[i][k].color==1)
                {
                    A[i][k].color=0;
                    boom(A,rows,cols);
                    *score=*score+1;//計分
                }
            }
        }
        /**********************************************************/
        for(i=0; i<=rows-1; i++)
        {
            for(k=0; k<=cols-1; k++)
            {
                if(b[i][k].color==1)
                {
                    n=1;
                    break;//確定還有沒有需要消除的
                }
                if(b[i][k].color==0)
                {
                    n=0;
                }
            }
            if(n==1)
            {
                break;
            }
        }
        fall(A,rows,cols);
    }
    free_matrix(rows,b);

    return A;
}

