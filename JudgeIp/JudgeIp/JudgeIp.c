#include"JudgeIp.h"
#include <WINDOWS.h>
#include<Windows.h>
/********************************************/
/***********��������InputIp******************/
/***********������ڲ���������***************/
/***********��������ֵ������ĸ���***********/
/***********�������ܣ�����ͼ����������*****/
/********************************************/
static  unsigned int InputIp(unsigned int *ArrIp)//��ֻ̬�ܱ�.cʹ��
{
	char InputChar = 0;
	unsigned int IpIndex = 0;
	printf("��������Ҫ�жϵ�IP��ַ��");
	while((InputChar = getchar()) != '\n')
	{
		ArrIp[IpIndex] = InputChar;
		IpIndex++;
	}
	return IpIndex;//����ĸ���
}
/********************************************/
/***********��������JudgeIp******************/
/***********������ڲ���������***************/
/***********��������ֵ����־���*************/
/***********�������ܣ��ж������IP��ַ���***/
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
/***********��������main*********************/
/***********������ڲ�������*****************/
/***********��������ֵ��int����**************/
/***********�������ܣ���������*************/
/********************************************/
int main()
{
	int iJudgeIp = 0;
	unsigned int ArrIp[MAX_INPUT] = {0};
	unsigned int IpIndex = InputIp(ArrIp);//���뱣�浽A
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
