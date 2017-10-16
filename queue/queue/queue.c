#include <stdio.h>
#include <stdlib.h>

typedef struct	queue{
	int queueArr[100];//定义队列空间
	int head;         //队列头部
	int tail;         //队列尾部
}queue;

/*
解密qq
*/
int queueDecodeQQ ( int *queueQQ,int head,int tail ,int *desQQ )
{
	int index = 0;
	if (( NULL == queueQQ )&&( NULL == desQQ))
	{
		return -1;
	}
	//进行解密
	while( head < tail )//条件是不为空
	{
		desQQ[index] = queueQQ[head];//将删除的数保留到desQQ数组，即就是真正的qq序列
		head++;
		queueQQ[tail] = queueQQ[head];//将head放到尾部
		tail++;
		head++;
		index++;
	}
	return 0;
}

/*
主函数
*/
int main()
{
	int index = 0;
	//定义队列
	queue queueQQ;
	//定义目的qq存放数组
	int desQQ[9] = {0};
	//输入
	printf("请输入要解密的qq:");
	for ( ; index < 9; index++ )
	{
		scanf("%d",&queueQQ.queueArr[index]);
	}
	//初始化对头和队尾
	queueQQ.head = 0;
	queueQQ.tail = 9;//队列尾部应该指向实际队列的最后一个数的下一个，保证当tail = head队列为空。
	//解密
	queueDecodeQQ (queueQQ.queueArr,queueQQ.head,queueQQ.tail,desQQ);
	//输出打印
	for ( index = 0; index < 9; index++ )
	{
		printf("%d ",desQQ[index]);
	}
	//换行
	printf("\n");
	//停止程序，可以保留那个黑框框（doc命令框）便于查看
	system("pause");
	return 0;
}