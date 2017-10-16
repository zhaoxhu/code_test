#include"arithmeticProgression.h"
#include<stdio.h>
#include<stdlib.h>

/*
输入函数
*/
static void inputNumber(int *number)
{
	printf("请输入要求的等差数列的第几项：");
	scanf("%d",number);
}
int main()
{
	int number = 0;
	int result = 0;
	int returnValue = 0;
	inputNumber(&number);//输入
	returnValue = arithmeticProgression(number,&result);
	if(FALSE == returnValue) //出错检测
	{
		printf("输入出错或结构超过int类型\n");
		system("pause");
		return 0;
	}
	printf("%d",result);
	printf("\n");
	system("pause");
	return 0;
}