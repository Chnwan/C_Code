#pragma once
//ͷ�ļ��İ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

//��ʼ������
void Initboard(char Board[ROW][COL], int row, int col);

//��ӡ����
 void Display(char Board[ROW][COL], int row, int col);
 //�����
 void Playermove(char Board[ROW][COL], int row, int col);
 //��������
 void Computermove(char Board[ROW][COL], int row, int col);
 //�ж���Ӯ
 char Is_win(char Board[ROW][COL], int row, int col);





