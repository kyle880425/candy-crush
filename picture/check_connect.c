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

    /****************************���ʫ᪺�Ĥ@�覸����************************/
    for(i=0; i<=rows-1; i++)
        {
            for(k=0; k<=cols-1; k++)
            {
                b[i][k].color=0;
            }
        }
        for(i=0; i<=rows-3; i++)//�ˬd����
        {
            for(k=0; k<=cols-1; k++)//�̦h���˼ƲĤT��
            {
                if(A[i][k].color==A[i+1][k].color && A[i+2][k].color==A[i][k].color)//�T�w���T�Ӭ۳s
                {
                    l=3;
                    for(j=i+3; j<=rows-1; j++)//�T�w���U���٦��S���۳s
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
                for(m=0; m<l; m++)//�����s��}�G����m
                {
                    b[i+m][k].color=1;
                }
                l=0;
            }
        }

        for(i=0; i<=rows-1; i++)//�ˬd���
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

        /**************************�p��&�p��***************************/
        for(i=0; i<=rows-1; i++)
        {
            for(k=0; k<=cols-1; k++)
            {
                if(b[i][k].color==1 && A[i][k].clear_enable==1)
                {
                    A[i][k].color=0;
                    boom(A,rows,cols);
                    *score=*score+1;//�p��
                }

                if(A[i][k].clear_enable==0)
                {

                    *score=*score+1;//�p��
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
                    break;//�T�w�٦��S���ݭn������
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

        //�Ĥ@�覸��������

        for(i=0; i<=rows-1; i++)
        {
            for(k=0; k<=cols-1; k++)
            {
                A[i][k].clear_enable=1;//�Nclear_enable���ܬ�1
            }
        }


    /*************************************************************************/
    /*********************************�ѭ�************************************/
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
        for(i=0; i<=rows-3; i++)//�ˬd����
        {
            for(k=0; k<=cols-1; k++)//�̦h���˼ƲĤT��
            {
                if(A[i][k].color==A[i+1][k].color && A[i+2][k].color==A[i][k].color)//�T�w���T�Ӭ۳s
                {
                    l=3;
                    for(j=i+3; j<=rows-1; j++)//�T�w���U���٦��S���۳s
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
                for(m=0; m<l; m++)//�����s��}�G����m
                {
                    b[i+m][k].color=1;
                }
                l=0;
            }
        }

        for(i=0; i<=rows-1; i++)//�ˬd���
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

        /**************************�p��&�p��***************************/
        for(i=0; i<=rows-1; i++)
        {
            for(k=0; k<=cols-1; k++)
            {
                if(b[i][k].color==1)
                {
                    A[i][k].color=0;
                    boom(A,rows,cols);
                    *score=*score+1;//�p��
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
                    break;//�T�w�٦��S���ݭn������
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

