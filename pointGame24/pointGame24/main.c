#include<stdio.h>
#include<stdlib.h>
#include "pointGame24.h"
/*
���뺯������������ֵ���м��
*/
static int input(int *num1,int *num2,int *num3,int *num4)
{
	printf("������4�����֣�");
	scanf("%d%d%d%d",num1,num2,num3,num4);
	if((*num1>=1&&*num1<=10)&&(*num2>=1&&*num2<=10)&&(*num3>=1&&*num3<=10)&&(*num4>=1&&*num4<=10))
	{
		return 1;
	}
	return 0;
}

/*
����������������
*/
int main()
{
	int num1 = 0.0;
	int num2 = 0.0;
	int num3 = 0.0;
	int num4 = 0.0;
	if(0 == input(&num1,&num2,&num3,&num4))
	{
		printf("����������\n");
		system("pause");
		return 0;
	}
	if(1 == pointGame24(num1,num2,num3,num4))
	{
		printf("ture\n");
	}
	else
	{
		printf("false\n");
	}
	system("pause");
	return 0;
}
