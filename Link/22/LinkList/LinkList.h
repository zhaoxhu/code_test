#ifndef _LINKLIST_
#define _LINKLIST_

//加入头文件
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;//从新定义数据类型



//定义结构体
typedef struct Node{
	ElemType NewDate;
	struct Node *Pnext;
}Node,*Pnode;
Pnode InitLinkList(Pnode head);
bool LinkListCreateH(Pnode head,ElemType NewDate);//头插
bool DisplayLinkList(Pnode head);//打印
bool LinkListCreateT(Pnode head,ElemType NewDate);//尾插
Pnode* FindKthToTail(Pnode head,unsigned int k);
bool LinkListInsertI(Pnode head,unsigned int i);
bool LinkListDelete(Pnode head,ElemType DeleteDate);
bool LinkListFree(Pnode head);
bool LinkListNumber(Pnode head);
#endif