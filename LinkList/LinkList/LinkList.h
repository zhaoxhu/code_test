#ifndef _LINKLIST_
#define _LINKLIST_

/***************************���ͷ�ļ�*************************/
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;//���¶�����������

#define MAXARR  100   //����ܽ��յ���

//����ṹ��
typedef struct Node{
	ElemType NewDate;
	struct Node *Pnext;
}Node,*Pnode;



/***************************��������*************************/
Pnode InitLinkList(Pnode head);
bool LinkListCreate(Pnode head);
bool DisplayLinkList(Pnode head);//��ӡ
bool LinkListDelete(Pnode head);
bool LinkListFree(Pnode head);


#endif  //_LINKLIST_