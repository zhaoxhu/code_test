
#include<stdio.h>
#include<stdlib.h>
/********************************************/
/***********��������MaxContinueOne***********/
/***********������ڲ�����һ���ֽڵ���********/
/***********��������ֵ�������������*********/
/*********�������ܣ��ҳ�һ���ֽ��������������/
/******************************************/
int MaxContinueOne(char Input)
{
	int ret = 0;
	int index = 0;
	int index2 = 0;
	int Arr1[8] = {0};//�����������һ���ֽڶ�Ӧ�Ķ�����
	int Arr2[8] = {0};//�������1�ļ���
	for(;index<8;index++)                 //�����������λ�ŵ�����arr1��
	{
		Arr1[index] = Input&1;
		Input >>= 1;
	}
	for(index = 0;index<8;index++)        //������������1�ŵ�����arr2��
	{
		if(1 == Arr1[index])
		{
			ret++;
		}
		else
		{
			Arr2[index2] = ret;
			index2++;
			ret = 0;
		}
	}
	Arr2[index2] = ret;//�����һ��1�ĸ���
	index = 0;
	for(;index<8;index++)          //�ҳ����ĵ�����������Ҫ�ҵ���
	{
		int temp = 0;
		if(Arr2[index] > ret)
		{	
			temp = Arr2[index];
			ret = temp;
		}
	}
	return ret;
}
/********************************************/
/***********��������main**********************/
/***********������ڲ�������******************/
/***********��������ֵ��0********************/
/*********�������ܣ���������***************/
/******************************************/
int main()
{
	int input = 0;
	printf("����������");
	scanf("%d",&input);
	while((input > 255)||(input < 0))
	{
		printf("�������������һ���ֽ�\n");
		printf("���������룺");
		scanf("%d",&input);	
	}
	printf("%d",MaxContinueOne(input));
	printf("\n");
	system("pause");
	return 0;
}