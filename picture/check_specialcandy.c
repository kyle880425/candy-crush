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
int check_specialcandy(candy **A,int rows,int cols,int movex,int movey){

        int i=0,j=0,k=0,l=0;

        /**************檢查相連數量*****************/
        for(i=0; i<=rows-3; i++)//檢查直排
        {
            //最多找到倒數第三個

                if(A[i][movex].color==A[i+1][movex].color && A[i+2][movex].color==A[i][movex].color)//確定有三個相連
                {
                    l=3;
                    for(j=i+3; j<=rows-1; j++)//確定接下來還有沒有相連
                    {
                        if(A[i][movex].color==A[j][movex].color)
                        {
                            l=l+1;
                        }
                        else
                        {
                            break;
                        }
                    }

                printf("l=%d\n",l);
                /********************由相連數檢查是否產生特殊糖果********************/
                if(l==5){

                    A[movey][movex].kind=4;
                    A[movey][movex].clear_enable=0;
                    printf("color ball");
                    return 4;
                }
                if(movex-2>=0){
                    if(A[movey][movex].color==A[movey][movex-1].color && A[movey][movex].color==A[movey][movex-2].color){

                        A[movey][movex].kind=3;
                        A[movey][movex].clear_enable=0;
                        printf("candy bag");
                        return 3;
                    }
                }
                if(movex+2<=cols-1){
                    if(A[movey][movex].color==A[movey][movex+1].color && A[movey][movex].color==A[movey][movex+2].color){

                        A[movey][movex].kind=3;
                        A[movey][movex].clear_enable=0;
                        printf("candy bag");
                        return 3;
                    }
                }
                if(l==4){
                    A[movey][movex].kind=1;
                    A[movey][movex].clear_enable=0;
                    printf("stripe candy");
                    return 2;
                }
                }
                l=0;

        }

        //檢查橫排

            for(k=0; k<=cols-3; k++)
            {
                if(A[movey][k].color==A[movey][k+1].color && A[movey][k].color==A[movey][k+2].color)
                {
                    l=3;
                    for(j=k+3; j<=cols-1; j++)
                    {
                        if(A[movey][k].color==A[movey][j].color)
                        {
                            l=l+1;
                        }
                        else
                        {
                            break;
                        }
                    }

                printf("l=%d\n",l);
                /********************由相連數檢查是否產生特殊糖果********************/
                if(l==5){

                    A[movey][movex].kind=4;
                    A[movey][movex].clear_enable=0;
                    printf("color ball");
                    return 4;
                }
                if(movey-2>=0){
                    if(A[movey-1][movex].color==A[movey][movex].color && A[movey-2][movex].color==A[movey][movex].color){

                        A[movey][movex].kind=3;
                        A[movey][movex].clear_enable=0;
                        printf("candy bag");
                        return 3;
                    }
                }
                if(movey+2<=rows-1){
                    if(A[movey-1][movex].color==A[movey][movex].color && A[movey-2][movex].color==A[movey][movex].color){

                        A[movey][movex].kind=3;
                        A[movey][movex].clear_enable=0;
                        printf("candy bag");
                        return 3;
                    }
                }
                if(l==4){
                    A[movey][movex].kind=2;
                    A[movey][movex].clear_enable=0;
                    printf("stripe candy");
                    return 2;
                }
                }
                l=0;
            }

return 0;
}
