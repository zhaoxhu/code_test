#include"LinkList.h"
Pnode InitLinkList(Pnode head)
{
	head = (Pnode)malloc(sizeof(Node));
	if(NULL == head)
	{
		return NULL;//ÉêÇëÊ§°Ü
	}
	head->NewDate = 0;
	head->Pnext = NULL;
	return head;
}
bool LinkListCreateH(Pnode head,ElemType NewDate)
{
	if(NULL == head)
	{
		return false;//Á´±íÎª¿Õ
	}
	Pnode NewNode = NULL;
	NewNode = (Pnode)malloc(sizeof(Node));
	if(NULL == NewNode)
	{
		return false;//ÉêÇë¿Õ¼äÊ§°Ü
	}
	NewNode->NewDate = NewDate;
	NewNode->Pnext = head->Pnext;
	head->Pnext = NewNode;
	return true;
}
bool LinkListCreateT(Pnode head,ElemType NewDate)
{
	if(NULL == head)
	{
		return false;//Á´±íÎª¿Õ
	}
	Pnode TempNode = NULL;
	Pnode NewNode = (Pnode)malloc(sizeof(Node));
	NewNode->NewDate = NewDate;
	NewNode->Pnext = NULL;
	TempNode = head->Pnext;
	while(NULL != TempNode)
	{
		TempNode = TempNode->Pnext;
	}
	TempNode = NewNode;
	return true;
	//TempNode = TempNode->Pnext;

}
Pnode* FindKthToTail(Pnode head,unsigned int k);
bool LinkListInsertI(Pnode head,unsigned int i);
bool LinkListDelete(Pnode head,ElemType DeleteDate);
bool LinkListFree(Pnode head)
{
	if(NULL == head)
	{
		return false;
	}
	free(head);
	return true;
}
bool DisplayLinkList(Pnode head)
{
	if(NULL == head)
	{
		return false;//¿ÕÁ´±í
	}
	Pnode TempNode = NULL;
	TempNode = head->Pnext;
	while(NULL != TempNode)
	{
		printf("%d",TempNode->NewDate);
		TempNode = TempNode->Pnext;
	}
	printf("\n");
	return true;
}
int main()
{
	Pnode NewHead = NULL;
	NewHead = InitLinkList(NewHead);
	for(int i = 0;i<10;i++)
	{
		LinkListCreateH(NewHead,i);
	}
	DisplayLinkList(NewHead);
	for(int i = 0;i<10;i++)
	{
		LinkListCreateT(NewHead,i);
	}
	DisplayLinkList(NewHead);
	system("pause");
}