#ifndef _LINKLIST_
#define _LINKLIST_

//����ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;//���¶�����������



//����ṹ��
typedef struct Node{
	ElemType NewDate;
	struct Node *Pnext;
}Node,*Pnode;
Pnode InitLinkList(Pnode head);
bool LinkListCreateH(Pnode head,ElemType NewDate);//ͷ��
bool DisplayLinkList(Pnode head);//��ӡ
bool LinkListCreateT(Pnode head,ElemType NewDate);//β��
Pnode* FindKthToTail(Pnode head,unsigned int k);
bool LinkListInsertI(Pnode head,unsigned int i);
bool LinkListDelete(Pnode head,ElemType DeleteDate);
bool LinkListFree(Pnode head);
bool LinkListNumber(Pnode head);
#endif