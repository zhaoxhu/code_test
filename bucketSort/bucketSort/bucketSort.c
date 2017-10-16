#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0;
	int j = 0;
	int temp = 0;
	/*假如是5个数排序，且数都小于10。举例说明桶排序*/
	int bucketArr[11] = {0};//11个桶
	printf("请输入要输入的5个数，小于等于10：");
	for(;i<5;i++)
	{
		scanf("%d",&temp);
		bucketArr[temp]++;
	}
	//从小到大，从大到小则i = 10即可
	for(i = 0;i < 11;i++)//桶数
	{
		for(j = 0;j < bucketArr[i];j++)
		{
			printf("%d",i);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}