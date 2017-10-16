#include "LINK_LIST.h"




bool InitList(NODE *phead)
{
	if (phead == NULL)
	{
		return false;
	}

	phead->next = NULL;
	return true;
}

static NODE *AllocNode()
{
	NODE *tmp = (NODE *)malloc(sizeof(NODE));
	if (tmp == NULL)
	{
		printf("½áµãÉêÇëÊ§°Ü\n");
		return NULL;
	}

	return tmp;
}



//                   phead         200
bool InsertHead(NODE *phead,ELEM_TYPE val)
{
	NODE *tmp = AllocNode();
	tmp->data = val;

	tmp->next = phead->next;
	phead->next = tmp;

	return true;
}


bool InsertTail(NODE *phead, ELEM_TYPE val)
{
	NODE *tmp = AllocNode();
	tmp->data = val;

	NODE *p = phead;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = tmp;
	tmp->next = NULL;

	return true;
}

void DisplayList(NODE *phead)
{
	NODE *p = phead->next;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

bool DestoryList(NODE *phead)
{
	if (phead == NULL)
	{
		return false;
	}
	NODE *tmp = phead->next;

	while(tmp != NULL)
	{
		phead->next = tmp->next;
		free(tmp);
		tmp = phead->next;
	}

	return true;
}