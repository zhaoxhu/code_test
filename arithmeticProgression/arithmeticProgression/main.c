#include"arithmeticProgression.h"
#include<stdio.h>
#include<stdlib.h>

/*
���뺯��
*/
static void inputNumber(int *number)
{
	printf("������Ҫ��ĵȲ����еĵڼ��");
	scanf("%d",number);
}
int main()
{
	int number = 0;
	int result = 0;
	int returnValue = 0;
	inputNumber(&number);//����
	returnValue = arithmeticProgression(number,&result);
	if(FALSE == returnValue) //������
	{
		printf("��������ṹ����int����\n");
		system("pause");
		return 0;
	}
	printf("%d",result);
	printf("\n");
	system("pause");
	return 0;
}