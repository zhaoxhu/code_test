#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TURE 1
#define MAX_INPUT_NUMBER 100
int BubbleSort(int *InputArr,int SizeArr)
{
	int i = 0;
	int j = 0;
	int flag = 0; //定义标志位优化冒泡排序
	if(NULL == InputArr)
	{
		return FALSE;
	}
	for(i = 0;i < SizeArr-1;i++)
	{
		for(j = 0;j < SizeArr-i-1;j++)
		{
			int temp = 0;
			if(InputArr[j] > InputArr[j+1])
			{
				flag = 1;
				temp = InputArr[j];
				InputArr[j] = InputArr[j+1];
				InputArr[j+1] = temp;
			}
		}
		if(0 == flag)   
			break;
	}
	return TURE;
}
int CastRepeat(int *InputArr,int InputSize)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int flag = 0;
	int ChangeSize = InputSize;
	if(NULL == InputArr)
	{
		return FALSE;
	}
	for(;i<ChangeSize;i++)
	{
		for(j = i;j < ChangeSize;j++)
		{	
			flag = 0;
			if(InputArr[i] == InputArr[j+1])
			{
				flag = 1;
				ChangeSize--;
				for(k = j+1;k < ChangeSize;k++)
				{
					InputArr[k] = InputArr[k+1];
				}
			}
			if(1 == flag)
			{
				j--;
			}
		}
		
		
	}
	return ChangeSize;
}
int InputFunction(int *InputArray,int *InputParam)
{
	int index = 0;
	if(NULL == InputArray)
	{
		return FALSE;
	}
	printf("请输入随机数的个数：");
	scanf("%d",InputParam);
	printf("请输入随机数组：");
	for(;index < *InputParam;index++)
	{
		scanf("%d",&InputArray[index]);
	}
	return TURE;
}
int main()
{
/*	int InputParam = 0;
    int index = 0;
	int CaseRepeatNumber = 0;
	int InputArray[MAX_INPUT_NUMBER] = {0};
    InputFunction(InputArray,&InputParam);
	CaseRepeatNumber = CastRepeat(InputArray,InputParam);
	BubbleSort(InputArray,CaseRepeatNumber);
	for(;index < CaseRepeatNumber+1;index++)
	{
		printf("%d",InputArray[index]);
	}*/
	int i = 0;
	int ret = 0;
	int arr[10] = {9,9,9,8,7,8,5,5,5,6};
	ret = CastRepeat(arr,11);
	for(;i<ret;i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}