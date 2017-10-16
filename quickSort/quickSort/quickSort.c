#include <stdio.h>
#include <stdlib.h>
int sortArr[10] = {0};
int quickSort(int left,int right)
{
	int i = left;
	int j = right;
	int temp = sortArr[i];//用来存放基数
	if ( left > right )
	{
		return -1;
	}
	while ( i != j )
	{
		while ( sortArr[j] <= temp && i < j )//找小于基准数的数
		{
			j--;
		}
		while ( sortArr[i] >= temp && i < j )//找小于基准数的数
		{
			i++;
		}
		
		if ( i < j )//判断下标并交换两个数
		{
			int tem = sortArr[i];
			sortArr[i] = sortArr[j];
			sortArr[j] = tem;
		}
	}
	//当两个下标相等时，交换基数和i下标的数。目的是将小于基准数的数
	//全部放到基准数的左边，大于基准数的数放到基准数的右边
	sortArr[left] = sortArr[i];
	sortArr[i] = temp;

	//递归调用quickSort函数。
	quickSort(left,i-1);//递归处理基数左边的数
	quickSort(i+1,right);//递归处理基数右边的数
	return 0;
}
int main()
{
	int index = 0;
	printf("请输入要排序的10个数：");
	for ( ;index < 10; index++ )
	{
		scanf("%d",&sortArr[index]);
	}
	quickSort(0,9);
	for ( index = 0;index < 10;index++ )
	{
		printf("%d ",sortArr[index]);
	}
	printf("\n");
	system("pause");
	return 0;
}