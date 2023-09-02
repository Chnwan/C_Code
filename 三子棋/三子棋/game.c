#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//��ʼ������
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

//��ӡ����
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

//�����
void Playermove(char Board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("�������>:\n");
		printf("���������꣺\n");
		scanf("%d %d", &x, &y);
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�ж������Ƿ�ռ��
			if (Board[x - 1][y - 1] == ' ')
			{
				Board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã�����������\a\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\a\n");
		}
	}

}

//��������
void Computermove(char Board[ROW][COL], int row, int col)
{
	printf("������\n");
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

//�ж������Ƿ�����
//���˾ͷ���0
//û���ͷ���1
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
				return 0; //��������
			}
		}
	}

	return 1; //����û��
}

//�ж���Ӯ
//���Ӯ���� *
//����Ӯ���� #
//ƽ�ַ��� Q
//��Ϸ�������� C
char Is_win(char Board[ROW][COL], int row, int col)
{
	//�ж�����
	int i = 0;

	for (i = 0; i < row; i++)
	{
		if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][0] != ' ')
		{
			return Board[i][1];
		}
	}
	//�ж�����
	for (i = 0; i <= col; i++)
	{
		if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] && Board[1][i] != ' ')
		{
			return Board[1][i];
		}
	}

	//�ж϶Խ���
	if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[1][1] != ' ')
	{
		return Board[1][1];
	}
	if (Board[2][0] == Board[1][1] && Board[1][1] == Board[0][2] && Board[1][1] != ' ')
	{
		return Board[1][1];
	}

	//�ж��Ƿ�ƽ��
	//û��ƽ�־ͷ���c
	int ret = Is_full(Board, row, col);

	if (ret == 1)
	{
		printf("ƽ��\n");
	}
	else
	{
		//������Ϸ
		return 'c';
	}
}

