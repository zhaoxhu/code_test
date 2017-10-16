#ifndef _LINKLIST_
#define _LINKLIST_

/***************************添加头文件*************************/
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;//从新定义数据类型

#define MAXARR  100   //最大能接收的数

//定义结构体
typedef struct Node{
	ElemType NewDate;
	struct Node *Pnext;
}Node,*Pnode;



/***************************函数声明*************************/
Pnode InitLinkList(Pnode head);
bool LinkListCreate(Pnode head);
bool DisplayLinkList(Pnode head);//打印
bool LinkListDelete(Pnode head);
bool LinkListFree(Pnode head);


#endif  //_LINKLIST_