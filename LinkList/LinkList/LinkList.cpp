#include"LinkList.h"
/********************************************************/
/************函数名：InitLinkList***********************/
/************函数功能：初始化链表************************/
/************函数返回值：结构体**************************/
/************入口参数：链表头结点************************/
Pnode InitLinkList(Pnode head)
{
	head = (Pnode)malloc(sizeof(Node));
	if(NULL == head)
	{
		return NULL;//申请失败
	}
	head->NewDate = 0;
	head->Pnext = NULL;
	return head;
}
/********************************************************/
/************函数名：LinkListCreate**********************/
/************函数功能：按要求创建链表********************/
/************函数返回值：bool类型************************/
/************入口参数：链表头结点***********************/
bool LinkListCreate(Pnode head)
{
	if(NULL == head)
	{
		return false;//链表为空
	}
	int HeadNode = 0;
	int Number = 0;
	int ArrBuf[MAXARR] = {0};
	printf("输入个数和头结点：");
	scanf("%d%d",&Number,&HeadNode);
	printf("请输入要按规则插入的数：");
	for(int i = 0;i<(Number-1)*2;i++)
	{
		scanf("%d",&ArrBuf[i]);
	}
	Pnode NewNode = (Pnode)malloc(sizeof(Node));
	if(NULL == NewNode)
	{
		return false;//申请空间失败
	}
	NewNode->NewDate = HeadNode;
	NewNode->Pnext = head->Pnext;
	head->Pnext = NewNode;
	int IndexNode = 0;
	for(int j = 0;j<Number;j++)
	{
		Pnode NewNode = (Pnode)malloc(sizeof(Node));
		
		if(NULL == NewNode)
		{
			return false;//申请空间失败
		}
	    Pnode TempNode = head->Pnext;
		while((ArrBuf[IndexNode+1] != TempNode->NewDate))
		{
			if(NULL == TempNode->Pnext)
			{
				return false;
			}
			TempNode = TempNode->Pnext;
		}
		if(NULL == TempNode->Pnext)
		{
			NewNode->NewDate = ArrBuf[IndexNode];
			NewNode->Pnext = NULL;
			TempNode->Pnext = NewNode;
		}
		else
		{
			NewNode->NewDate = ArrBuf[IndexNode];
			NewNode->Pnext = TempNode->Pnext;
			TempNode->Pnext = NewNode;
		}
		IndexNode+=2;
	}
	return true;
}

/********************************************************/
/************函数名：LinkListDelete**********************/
/************函数功能：删除链表中的数通过scanf传入*******/
/************函数返回值：bool类型************************/
/************入口参数：链表头结点********8***************/
bool LinkListDelete(Pnode head)
{
	if(NULL == head)
	{
		return false;//链表为空
	}
	ElemType DeleteDate = 0;
	printf("请输入要删除的数：");
	scanf("%d",&DeleteDate);
	Pnode TempNodeB = head->Pnext;
	Pnode TempNodeA = head;	
	while(DeleteDate != TempNodeB->NewDate)
	{
		TempNodeB = TempNodeB->Pnext;
		TempNodeA = TempNodeA->Pnext;
	}
	TempNodeA->Pnext = TempNodeB->Pnext;
	if(NULL == head)
	{
		return false;//如果删出完为空链表则返回false
	}
	return true;
}
/********************************************************/
/************函数名：LinkListFree***********************/
/************函数功能：free链表**************************/
/************函数返回值：bool类型************************/
/************入口参数：链表头结点************************/
bool LinkListFree(Pnode head)
{
	if(NULL == head)
	{
		return false;
	}
	Pnode TmpeNode = head->Pnext;
	while(NULL != TmpeNode)
	{
		head->Pnext = TmpeNode->Pnext;
		free(TmpeNode);
		TmpeNode = head->Pnext;
	}
	return true;
}
/********************************************************/
/************函数名：DisplayLinkList***********************/
/************函数功能：打印显示链表**************************/
/************函数返回值：bool类型***************************/
/************入口参数：链表头结点***************************/
bool DisplayLinkList(Pnode head)
{
	if(NULL == head)
	{
		return false;//空链表
	}
	Pnode TempNode = NULL;
	TempNode = head->Pnext;
	while(NULL != TempNode)
	{
		printf("%d  ",TempNode->NewDate);
		TempNode = TempNode->Pnext;
	}
	printf("\n");
	return true;
}
/********************************************************/
/************函数名：main********************************/
/************函数功能：程序的入口*************************/
/************函数返回值：int*****************************/
/************入口参数：空********************************/
int main()
{
	Pnode NewHead = NULL;
	NewHead = InitLinkList(NewHead);//初始化链表
	LinkListCreate(NewHead);//按要求创建链表
	DisplayLinkList(NewHead);//打印显示链表
	LinkListDelete(NewHead);//删除要删除的节点
	DisplayLinkList(NewHead);//打印显示删除后的链表
	system("pause");
	LinkListFree(NewHead);//free链表
	return 0;
}