#pragma once
//头文件的包含
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

//初始化棋盘
void Initboard(char Board[ROW][COL], int row, int col);

//打印棋盘
 void Display(char Board[ROW][COL], int row, int col);
 //玩家走
 void Playermove(char Board[ROW][COL], int row, int col);
 //电脑下棋
 void Computermove(char Board[ROW][COL], int row, int col);
 //判断输赢
 char Is_win(char Board[ROW][COL], int row, int col);





