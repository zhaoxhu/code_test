#include <stdio.h>
#include <stdlib.h>

typedef struct	queue{
	int queueArr[100];//������пռ�
	int head;         //����ͷ��
	int tail;         //����β��
}queue;

/*
����qq
*/
int queueDecodeQQ ( int *queueQQ,int head,int tail ,int *desQQ )
{
	int index = 0;
	if (( NULL == queueQQ )&&( NULL == desQQ))
	{
		return -1;
	}
	//���н���
	while( head < tail )//�����ǲ�Ϊ��
	{
		desQQ[index] = queueQQ[head];//��ɾ������������desQQ���飬������������qq����
		head++;
		queueQQ[tail] = queueQQ[head];//��head�ŵ�β��
		tail++;
		head++;
		index++;
	}
	return 0;
}

/*
������
*/
int main()
{
	int index = 0;
	//�������
	queue queueQQ;
	//����Ŀ��qq�������
	int desQQ[9] = {0};
	//����
	printf("������Ҫ���ܵ�qq:");
	for ( ; index < 9; index++ )
	{
		scanf("%d",&queueQQ.queueArr[index]);
	}
	//��ʼ����ͷ�Ͷ�β
	queueQQ.head = 0;
	queueQQ.tail = 9;//����β��Ӧ��ָ��ʵ�ʶ��е����һ��������һ������֤��tail = head����Ϊ�ա�
	//����
	queueDecodeQQ (queueQQ.queueArr,queueQQ.head,queueQQ.tail,desQQ);
	//�����ӡ
	for ( index = 0; index < 9; index++ )
	{
		printf("%d ",desQQ[index]);
	}
	//����
	printf("\n");
	//ֹͣ���򣬿��Ա����Ǹ��ڿ��doc����򣩱��ڲ鿴
	system("pause");
	return 0;
}