#include"JudgeIp.h"
#include <WINDOWS.h>
#include<Windows.h>
/********************************************/
/***********函数名：InputIp******************/
/***********函数入口参数：数组***************/
/***********函数返回值：输入的个数***********/
/***********函数功能：输入和计算输入个数*****/
/********************************************/
static  unsigned int InputIp(unsigned int *ArrIp)//静态只能本.c使用
{
	char InputChar = 0;
	unsigned int IpIndex = 0;
	printf("请您输入要判断的IP地址：");
	while((InputChar = getchar()) != '\n')
	{
		ArrIp[IpIndex] = InputChar;
		IpIndex++;
	}
	return IpIndex;//输入的个数
}
/********************************************/
/***********函数名：JudgeIp******************/
/***********函数入口参数：数组***************/
/***********函数返回值：标志真假*************/
/***********函数功能：判断输入的IP地址真假***/
/********************************************/
int JudgeIp(unsigned int *Ip)
{
	int dot = 0;
	int section = 0;
	if( '.' == *Ip)
	{
		return 0;
	}
	if('0' == *Ip)
	{
		return 0;
	}
	while(*Ip)
	{
		if('.' == *Ip)
		{
			if('.' == *(Ip+1))
			{
				return 0;
			}
			dot++;
			if(dot>3)
			{
				return 0;
			}
			if(section >= 0 && section <=255)
            { 
                section = 0; 
            }else{ 
                return 0; 
            } 
		}
		else if(*Ip >= '0' && *Ip <= '9')
        { 
            section = section * 10 + (*Ip - '0'); 
        }
		else
		{ 
            return 0; 
        } 
        Ip++;    
	}
	if(section >= 0 && section <=255)
    { 
       if(3 == dot)
        {
			return 1;
        }
    } 
	else
	{
		return 0;
	}
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
	unsigned int ArrIp[MAX_INPUT] = {0};
	unsigned int IpIndex = InputIp(ArrIp);//输入保存到A
	iJudgeIp = JudgeIp(ArrIp);
	if(1 == iJudgeIp)
	{
		printf("yes");
		printf("\n");
	}
	else
	{
		printf("no");
		printf("\n");
	}
	system("pause");
	return 0;
}
