#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
�жϻ���
*/
int statckJudge(char *arr,int size)
{
	char temp[100] = {0};//���ǰ�벿��
	int index = 0;
	int top = 0;//ջ��ʼֵ
	int next = 0;//��벿���±�
	int mid = size/2 - 1;//�м�λ��
	//��⴫����ָ���Ƿ�Ϊ��
	if ( NULL == arr)
	{
		return -1;
	}
	//���ַ�����ǰ�벿�ַŵ�temp��
	for ( ; index <= mid ;index++ )
	{
		temp[++top] = arr[index];
	}
	//��ȡ��벿����ʼ�±�
	if ( 0 == size%2 )
	{
		next = mid+1;
	}
	else
	{
		next = mid+2;
	}
	//�ж��Ƿ�Ϊ����
	for (index = next;index < size;index++)
	{
		if ( temp[top] != arr[index] )
		{
			return -1;
		}
		top--;
	}
	if ( 0 == top )//˵��ȫ���ַ�������������Ϊ���ġ�
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int sizeOfArr = 0;//�����ַ�������
	int ret = 0;//���պ�������ֵ
	char inputArr[100] = {0};//װ�ػ���
	printf("������Ҫ�жϵ��ַ�����");
	gets(inputArr);//��ȡ����
	sizeOfArr = strlen(inputArr);//��ȡ�����ַ�������
	ret = statckJudge(inputArr,sizeOfArr);//���շ���ֵ
	//�жϷ���ֵ��������Ӧ���
	if ( 0 == ret)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	system("pause");//����ͣ����
	return 0;
}