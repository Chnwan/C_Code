#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("***************************\n");
	printf("****      1.  play     ****\n");
	printf("****      0.  exit     ****\n");
	printf("***************************\n");

}

void game()
{
	char Board[ROW][COL];
	//初始化棋盘
	Initboard(Board, ROW, COL);
	//打印棋盘
	Display(Board, ROW, COL);
	char ret = 0;  //接收返回的游戏状态
	
	while (1)
	{
		//玩家下棋
		Playermove(Board, ROW, COL);
		Display(Board, ROW, COL);
		//判断输赢
		 ret = Is_win(Board, ROW, COL);
		if (ret != 'c')
			break;

		//电脑下棋
		Computermove(Board, ROW, COL);
		Display(Board, ROW, COL);
		 ret = Is_win(Board, ROW, COL);
		if (ret != 'c')
			break;

	}

	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}

	Display(Board, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		//打印菜单
		menu();
		printf("请选择是否开始>:\n");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入>:");
			break;

		}

	} while (input);
	
	return 0;
}