
#include<stdio.h>
#include<stdlib.h>
/********************************************/
/***********函数名：MaxContinueOne***********/
/***********函数入口参数：一个字节的数********/
/***********函数返回值：最大连续的数*********/
/*********函数功能：找出一个字节中最大连续的数/
/******************************************/
int MaxContinueOne(char Input)
{
	int ret = 0;
	int index = 0;
	int index2 = 0;
	int Arr1[8] = {0};//用来存放输入一个字节对应的二进制
	int Arr2[8] = {0};//用来存放1的集合
	for(;index<8;index++)                 //将输入的数按位放到数组arr1中
	{
		Arr1[index] = Input&1;
		Input >>= 1;
	}
	for(index = 0;index<8;index++)        //将所有连续的1放到数组arr2中
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
	Arr2[index2] = ret;//放最后一组1的个数
	index = 0;
	for(;index<8;index++)          //找出最大的的数，即就是要找的数
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
/***********函数名：main**********************/
/***********函数入口参数：无******************/
/***********函数返回值：0********************/
/*********函数功能：程序的入口***************/
/******************************************/
int main()
{
	int input = 0;
	printf("请输入数：");
	scanf("%d",&input);
	while((input > 255)||(input < 0))
	{
		printf("输入的数不符合一个字节\n");
		printf("请重新输入：");
		scanf("%d",&input);	
	}
	printf("%d",MaxContinueOne(input));
	printf("\n");
	system("pause");
	return 0;
}