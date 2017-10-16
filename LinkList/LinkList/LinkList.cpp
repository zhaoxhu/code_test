#include"LinkList.h"
/********************************************************/
/************��������InitLinkList***********************/
/************�������ܣ���ʼ������************************/
/************��������ֵ���ṹ��**************************/
/************��ڲ���������ͷ���************************/
Pnode InitLinkList(Pnode head)
{
	head = (Pnode)malloc(sizeof(Node));
	if(NULL == head)
	{
		return NULL;//����ʧ��
	}
	head->NewDate = 0;
	head->Pnext = NULL;
	return head;
}
/********************************************************/
/************��������LinkListCreate**********************/
/************�������ܣ���Ҫ�󴴽�����********************/
/************��������ֵ��bool����************************/
/************��ڲ���������ͷ���***********************/
bool LinkListCreate(Pnode head)
{
	if(NULL == head)
	{
		return false;//����Ϊ��
	}
	int HeadNode = 0;
	int Number = 0;
	int ArrBuf[MAXARR] = {0};
	printf("���������ͷ��㣺");
	scanf("%d%d",&Number,&HeadNode);
	printf("������Ҫ��������������");
	for(int i = 0;i<(Number-1)*2;i++)
	{
		scanf("%d",&ArrBuf[i]);
	}
	Pnode NewNode = (Pnode)malloc(sizeof(Node));
	if(NULL == NewNode)
	{
		return false;//����ռ�ʧ��
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
			return false;//����ռ�ʧ��
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
/************��������LinkListDelete**********************/
/************�������ܣ�ɾ�������е���ͨ��scanf����*******/
/************��������ֵ��bool����************************/
/************��ڲ���������ͷ���********8***************/
bool LinkListDelete(Pnode head)
{
	if(NULL == head)
	{
		return false;//����Ϊ��
	}
	ElemType DeleteDate = 0;
	printf("������Ҫɾ��������");
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
		return false;//���ɾ����Ϊ�������򷵻�false
	}
	return true;
}
/********************************************************/
/************��������LinkListFree***********************/
/************�������ܣ�free����**************************/
/************��������ֵ��bool����************************/
/************��ڲ���������ͷ���************************/
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
/************��������DisplayLinkList***********************/
/************�������ܣ���ӡ��ʾ����**************************/
/************��������ֵ��bool����***************************/
/************��ڲ���������ͷ���***************************/
bool DisplayLinkList(Pnode head)
{
	if(NULL == head)
	{
		return false;//������
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
/************��������main********************************/
/************�������ܣ���������*************************/
/************��������ֵ��int*****************************/
/************��ڲ�������********************************/
int main()
{
	Pnode NewHead = NULL;
	NewHead = InitLinkList(NewHead);//��ʼ������
	LinkListCreate(NewHead);//��Ҫ�󴴽�����
	DisplayLinkList(NewHead);//��ӡ��ʾ����
	LinkListDelete(NewHead);//ɾ��Ҫɾ���Ľڵ�
	DisplayLinkList(NewHead);//��ӡ��ʾɾ���������
	system("pause");
	LinkListFree(NewHead);//free����
	return 0;
}