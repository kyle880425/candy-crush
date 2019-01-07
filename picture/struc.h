#ifndef _STRUCTURE_HEADER_H_
#define _STRUCTURE_HEADER_H_

typedef struct Candy{
int color;
//六種顏色:1~6,  被削掉的:0 ,彩球:10
int kind;
/*
kind說明:
0普通
1橫條紋
2直條紋
3糖果包
4彩球
*/
int clear_enable;
//1:可以被消除 0:不能被消除
}candy;

#endif // _STRUCTURE_HEADER_H_




