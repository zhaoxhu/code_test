#include <stdio.h>
#include <stdlib.h>
#include "JudgeIp.h"
#include "intToIpOrIpToInt.h"
/********************************************/
/***********函数名：InputIp******************/
/***********函数入口参数：数组***************/
/***********函数返回值：输入的个数***********/
/***********函数功能：输入和计算输入个数*****/
/********************************************/
static  void InputIp(char *ArrIp,int *number)//静态只能本.c使用
{
	char InputChar = 0;
	int IpIndex = 0;
	printf("请您输入要转换成整数的IP地址：");
	while((InputChar = getchar()) != '\n')
	{
		ArrIp[IpIndex] = InputChar;
		IpIndex++;
	}
	printf("请输入要转换成IP地址的整数：");
	scanf("%d",number);
}

/********************************************/
/***********函数名：main*********************/
/***********函数入口参数：无*****************/
/***********函数返回值：int类型**************/
/***********函数功能：程序的入口*************/
/********************************************/
int main()
{
	int iJudgeIp = 0;
	int number = 0;
	char ArrIp[MAX_INPUT] = {0};//输入的IP地址
	int ip[4] = {0};//存放转换后的IP每个节点
	InputIp(ArrIp,&number);//输入保存到A
	iJudgeIp = JudgeIp(ArrIp);
	if(0 == iJudgeIp)//判断输入的IP地址是否有误
	{
		printf("输入的IP地址有错\n");
		return 0;

	}
	if( number > 2147483647 || number < -2147483647)
	{
		printf("输入的整数不合理\n");
		return 0;
	}
	else
	{
		intToIp(number,ip);
		displayIntToIp(ip);
		printf("\n");
		printf("%d",ipToInt(ArrIp));
		printf("\n");
	}
	system("pause");
	return 0;
}
