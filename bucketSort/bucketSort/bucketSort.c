#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0;
	int j = 0;
	int temp = 0;
	/*������5��������������С��10������˵��Ͱ����*/
	int bucketArr[11] = {0};//11��Ͱ
	printf("������Ҫ�����5������С�ڵ���10��");
	for(;i<5;i++)
	{
		scanf("%d",&temp);
		bucketArr[temp]++;
	}
	//��С���󣬴Ӵ�С��i = 10����
	for(i = 0;i < 11;i++)//Ͱ��
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