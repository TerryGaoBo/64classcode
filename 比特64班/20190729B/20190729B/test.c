#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("********0.exit********\n");
	printf("********1.play********\n");
	printf("**********************\n");
}
void game()
{
	char mine[ROWS][COLS] = {0};//存放雷
	char mineInfo[ROWS][COLS] = {0};//存放雷的信息(排查)
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(mineInfo,ROWS,COLS,'*');

	//Show(mine,ROW,COL);
	Show(mineInfo,ROW,COL);

	SetMine(mine,ROW,COL);
	//Show(mine,ROW,COL);
	FindMine(mine,mineInfo,ROW,COL);

}
int main()
{

	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入你的选择 -》");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请输入正确的数字\n");
			break;
		}
	}while(input);
	return 0;
}

