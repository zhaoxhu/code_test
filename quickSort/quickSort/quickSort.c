#include <stdio.h>
#include <stdlib.h>
int sortArr[10] = {0};
int quickSort(int left,int right)
{
	int i = left;
	int j = right;
	int temp = sortArr[i];//������Ż���
	if ( left > right )
	{
		return -1;
	}
	while ( i != j )
	{
		while ( sortArr[j] <= temp && i < j )//��С�ڻ�׼������
		{
			j--;
		}
		while ( sortArr[i] >= temp && i < j )//��С�ڻ�׼������
		{
			i++;
		}
		
		if ( i < j )//�ж��±겢����������
		{
			int tem = sortArr[i];
			sortArr[i] = sortArr[j];
			sortArr[j] = tem;
		}
	}
	//�������±����ʱ������������i�±������Ŀ���ǽ�С�ڻ�׼������
	//ȫ���ŵ���׼������ߣ����ڻ�׼�������ŵ���׼�����ұ�
	sortArr[left] = sortArr[i];
	sortArr[i] = temp;

	//�ݹ����quickSort������
	quickSort(left,i-1);//�ݹ鴦�������ߵ���
	quickSort(i+1,right);//�ݹ鴦������ұߵ���
	return 0;
}
int main()
{
	int index = 0;
	printf("������Ҫ�����10������");
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