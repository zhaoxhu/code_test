#include <stdio.h>
#include <stdlib.h>
#include "JudgeIp.h"
#include "intToIpOrIpToInt.h"
/********************************************/
/***********��������InputIp******************/
/***********������ڲ���������***************/
/***********��������ֵ������ĸ���***********/
/***********�������ܣ�����ͼ����������*****/
/********************************************/
static  void InputIp(char *ArrIp,int *number)//��ֻ̬�ܱ�.cʹ��
{
	char InputChar = 0;
	int IpIndex = 0;
	printf("��������Ҫת����������IP��ַ��");
	while((InputChar = getchar()) != '\n')
	{
		ArrIp[IpIndex] = InputChar;
		IpIndex++;
	}
	printf("������Ҫת����IP��ַ��������");
	scanf("%d",number);
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
	int number = 0;
	char ArrIp[MAX_INPUT] = {0};//�����IP��ַ
	int ip[4] = {0};//���ת�����IPÿ���ڵ�
	InputIp(ArrIp,&number);//���뱣�浽A
	iJudgeIp = JudgeIp(ArrIp);
	if(0 == iJudgeIp)//�ж������IP��ַ�Ƿ�����
	{
		printf("�����IP��ַ�д�\n");
		return 0;

	}
	if( number > 2147483647 || number < -2147483647)
	{
		printf("���������������\n");
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
