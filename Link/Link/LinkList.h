#ifndef _LINKLIST_
#define _LINKLIST_
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
typedef int ElemType;
//����ڵ�����
typedef struct Node{
	ElemType data;
    struct Node *pnext;
}Node;
Node *HeadInsertList();
Node *SeekTialList(Node *head,ElemType num);
#endif