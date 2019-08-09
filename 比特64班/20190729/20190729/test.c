#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("*******************\n");
	printf("******0.exit*******\n");
	printf("******1.play*******\n");
	printf("*******************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][ROW]= {0};// '0'  '\0'   0   NULL
	InitBoard(board,ROW,ROW,' ');
	ShowBoard(board,ROW,ROW);


	while(1)//只要有一方胜出，结束循环
	{
		PlayerMove(board,ROW,ROW);
		//玩家每走一步，需要判断是否赢了
		ret = IsWin(board,ROW,ROW);
		if(ret != ' ')
		{
			//可能平局，可能一方胜出
			break;
		}
		ShowBoard(board,ROW,ROW);

		//电脑走
		ComputerMove(board,ROW,ROW);
		ret = IsWin(board,ROW,ROW);
		if(ret != ' ')
		{
			//可能平局，可能一方胜出
			break;
		}
		ShowBoard(board,ROW,ROW);
	}
	//判断ret
	if(ret == 'x')
	{
		printf("玩家胜出\n");
	}
	if(ret == ' O')
	{
		printf("电脑胜出\n");
	}
	if(ret == 'Q')
	{
		printf("平局\n");
	}
}
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入您的选择：-》");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			printf("请输入正确的操作\n");
			break;
		}
	}while(input);
	return 0;
}