#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[][ROW],int row,int col,char set)
{
	int i = 0;
	int j = 0;
	for(i = 0;i < row;i++)
	{
		for(j = 0;j < row;j++)
		{
			board[i][j] = set;
		}
	}
}
void ShowBoard(char board[][ROW],int row,int col)
{
	int i = 0;
	int j = 0;
	for(i = 0;i < row;i++)
	{
		for(j = 0;j < col;j++)
		{
			printf(" %c ",board[i][j]);
			if(j < col-1)
			{
				printf("|");
			}
		}
		printf("\n");
		if(i < row-1)
		{
			for(j = 0;j < col;j++)
			{
				printf("---");
				if(j <  col-1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[][ROW],int row,int col)
{
	int x =0 ;
	int y = 0;
	while(1)//8,9
	{
		printf("玩家移动\n");
		printf("请输入1-3的坐标：\n");
		scanf("%d%d",&x,&y);
		//1、坐标合法  -》 坐标被占用    
		//退出循环：位置合法，并且没被占用，break
		if(x >= 1 && x <= 3 && y >=1 && y <= 3)
		{
			if(board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = 'x';
				break;
			}
			else
			{
				printf("位置已经被占用，请重新输入\n");
			}
		}
		else
		{
			printf("坐标不合法\n");
		}
		//2、坐标不合法
	}
}
static int IsFull(char board[][ROW],int row,int col)
{
	int i = 0;
	int j = 0;
	for(i = 0;i < row;i++)
	{
		for(j = 0;j < col;j++)
		{
			if(board[i][j] == ' ')
			{
				return 0;//没有满
			}
		}
	}
	return 1;
}
char IsWin(char board[][ROW],int row,int col)
{
	int i = 0;
	for(i = 0;i < row;i++)
	{
		//行
		if(board[i][0]==board[i][1] && board[i][1]==board[i][2] 
		&&board[i][0] != ' ')
		{
			return board[i][0];
		}
		//列
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i]
		&&board[0][i] != ' ')
		{
				return board[0][i];
		}
		//对角线
		if(board[0][0] == board[1][1] && board[1][1] == board[2][2]
		&& board[0][0] != ' ')
		{
			return board[0][0];
		}
		if(board[0][2] == board[1][1] && board[1][1] == board[2][0]
		&& board[0][2] != ' ')
		{
			return board[0][2];
		}

		if(IsFull(board,ROW,ROW))
		{
			return 'Q';//平局
		}
	}
	return ' ';//谁也没有赢
}

void ComputerMove(char board[][ROW],int row,int col)
{
	int x = 0;
	int y = 0;
	printf("电脑移动\n");
	while(1)
	{
		x = rand() % ROW;//[0-3)
		y = rand() % ROW;
		if(board[x][y] == ' ')
		{
			board[x][y] = 'O';
			break;
		}
	}
}
