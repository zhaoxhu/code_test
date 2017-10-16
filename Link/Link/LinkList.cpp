#include"LinkList.h"
Node *HeadInsertList(Node *head)
{
	
	Node *p = NULL;
	int i = 0;
	srand((unsigned int)time(0)); //随机数种子
    head = p = (Node *)malloc(sizeof(Node)); 
    head-> data = rand()%101; 
    head-> pnext = NULL; 
    for(i=1;i<N;i++) 
    { 
        p = p->pnext = (Node *)malloc(sizeof(Node)); 
        p->data = rand()%101; 
        p->pnext = NULL; 
    } 
      
    for(p = head;p;p=p->pnext) 
        printf("%d  ",p->data); 
	printf("\n");
	return head;

}
Node *SeekTialList(Node *head,ElemType num)
{
	Node *p = NULL;
	Node *q = NULL;     
	p = q = head;           
    if(num<=0)         
		return NULL;         
    while(num-1 > 0)     
    {
		if(q->pnext!= NULL)           
			q = q->pnext;         
        else            
			return NULL;        
        num--;    
	}           
	while(q->pnext != NULL)     
	{     	
		p = p->pnext;     
        q = q->pnext;   
   }      
   return p;

}
int main()
{
	Node *head = NULL;
	int num = 0;
	head = HeadInsertList(head);
	printf("请输入倒数第几个");
	scanf("%d",&num);
	if(NULL == SeekTialList(head,num))
	{
		printf("no");
	}
	else
	{
		printf("%d",SeekTialList(head,num)->data);
	}
	printf("\n");
	system("pause");
}