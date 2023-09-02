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
	//��ʼ������
	Initboard(Board, ROW, COL);
	//��ӡ����
	Display(Board, ROW, COL);
	char ret = 0;  //���շ��ص���Ϸ״̬
	
	while (1)
	{
		//�������
		Playermove(Board, ROW, COL);
		Display(Board, ROW, COL);
		//�ж���Ӯ
		 ret = Is_win(Board, ROW, COL);
		if (ret != 'c')
			break;

		//��������
		Computermove(Board, ROW, COL);
		Display(Board, ROW, COL);
		 ret = Is_win(Board, ROW, COL);
		if (ret != 'c')
			break;

	}

	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}

	Display(Board, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		//��ӡ�˵�
		menu();
		printf("��ѡ���Ƿ�ʼ>:\n");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�����������������>:");
			break;

		}

	} while (input);
	
	return 0;
}