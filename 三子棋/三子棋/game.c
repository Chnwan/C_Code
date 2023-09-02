#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//初始化棋盘
void Initboard(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			Board[i][j] = ' ';
		}
	}
}

//打印棋盘
void Display(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", Board[i][j]);
			if (j < row - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

//玩家走
void Playermove(char Board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家下棋>:\n");
		printf("请输入坐标：\n");
		scanf("%d %d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断坐标是否被占用
			if (Board[x - 1][y - 1] == ' ')
			{
				Board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入\a\n");
			}
		}
		else
		{
			printf("输入非法，请重新输入\a\n");
		}
	}

}

//电脑下棋
void Computermove(char Board[ROW][COL], int row, int col)
{
	printf("电脑走\n");
	while (1)
	{
		int x = rand() % ROW;
		int y = rand() % COL;

		if (Board[x][y] == ' ')
		{
			Board[x][y] = '#';
			break;
		}
	}
}

//判断棋盘是否下满
//满了就返回0
//没满就返回1
int Is_full(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (Board[i][j] == ' ')
			{
				return 0; //棋盘满了
			}
		}
	}

	return 1; //棋盘没满
}

//判断输赢
//玩家赢返回 *
//电脑赢返回 #
//平局返回 Q
//游戏继续返回 C
char Is_win(char Board[ROW][COL], int row, int col)
{
	//判断三行
	int i = 0;

	for (i = 0; i < row; i++)
	{
		if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][0] != ' ')
		{
			return Board[i][1];
		}
	}
	//判断三列
	for (i = 0; i <= col; i++)
	{
		if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] && Board[1][i] != ' ')
		{
			return Board[1][i];
		}
	}

	//判断对角线
	if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[1][1] != ' ')
	{
		return Board[1][1];
	}
	if (Board[2][0] == Board[1][1] && Board[1][1] == Board[0][2] && Board[1][1] != ' ')
	{
		return Board[1][1];
	}

	//判断是否平局
	//没有平局就返回c
	int ret = Is_full(Board, row, col);

	if (ret == 1)
	{
		printf("平局\n");
	}
	else
	{
		//继续游戏
		return 'c';
	}
}

