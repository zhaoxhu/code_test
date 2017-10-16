#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_PARAM_MIN_NUM 4

#define RET_ERR -1
#define RET_OK  0


typedef struct ListNode_s
{
	int m_nKey;
	struct ListNode_s *m_pNext;
}ListNode_t;

typedef struct List_s
{
	ListNode_t *head;
	ListNode_t *tail;
	int size;
}List_t;


/*
 *  创建节点
 * */
ListNode_t* nodeCreate(int key)
{
	ListNode_t* node = malloc(sizeof(ListNode_t));
	if(NULL != node)
	{
		node->m_nKey = key;
		node->m_pNext = NULL;
	}
	return node;
}


/*
 *  释放节点
 * */
int nodeFree(ListNode_t *node,ListNode_t **next)
{
	if(NULL == node)
	{
		return RET_ERR;
	}
	if(NULL != next)
	{
		*next = node->m_pNext;
	}
	free(node);
	return RET_OK;
}
 

/*
 *  创建列表
 * */
List_t *listCreate(void)
{
	List_t* list = malloc(sizeof(List_t));
	if(NULL != list) 
	{
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
	}
	return list;
}

/*
 *  释放列表
 * */
 int listFree(List_t *list)
 {
	 ListNode_t * node = NULL;
	 ListNode_t * next = NULL;
	 if(NULL == list)
	 {
		 return RET_ERR;
	 }
	 
	 node = list->head;
	 while(nodeFree(node,&next)) 
	 {
		 if(NULL != next)
		 {
			 node = next;
		 }
		 else
		 {
			 break;
		 }
	 }
	 free(list);
	 return RET_OK;
 }
 
/*
 *  将节点添加到列表尾
 * */
int listAddToTail(List_t *list,ListNode_t *node)
{
	if(NULL == list || NULL == node)
	{
		return RET_ERR;
	}
	// 如果链表为空
	if(NULL == list->head)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->m_pNext = node;
		list->tail = node;
	}
	list->size++;
	return list->size;
}


/*
 *  计算list 节点个数
 * */
 int countListSize(ListNode_t* pListHead)
 {
	 int size = 0;
	 ListNode_t *node = NULL;
	 if(NULL == pListHead)
	 {
		 return RET_ERR;
	 }
	 node = pListHead;
	 while(node)
	 {
		 size++;
		 node = node->m_pNext;
	 }
	 return size;
 }


/*
 *  打印list
 * */
int listPrint(List_t *list)
{
	ListNode_t *node = NULL;
	if(NULL == list)
	{
		return RET_ERR;
	}
	printf("list size:%d\n",list->size);
	node = list->head;
	while(node)
	{
		printf("[%d] ",node->m_nKey);
		node = node->m_pNext;
	}
	printf("\n");
	return RET_OK;
}


/*
 *  找到链表中倒数第k个结点
 * */
ListNode_t* findKthToTail(ListNode_t* pListHead,unsigned int k)
{
	int i = 0;
	int listSize = 0;
	ListNode_t *node = NULL;
	if(NULL == pListHead)
	{
		return NULL;
	}
	//先计算节点个数
	listSize = countListSize(pListHead);

	if(k < 0 || k >= listSize)
	{
		return NULL;
	}
	// 根据节点个数和k遍历
	node = pListHead;
	for(i = 0;i < listSize - k - 1;i++)
	{
		node = node->m_pNext;
	}
	return node;
}


/*
 *  根据命令行参数给list添加数据
 * */
int createTestList(List_t *list,int size,char *data[])
{
	int i = 0;
	int ret = RET_OK;
	if(NULL == list || NULL == data || size <= 0)
	{
		ret = RET_ERR;
	}
	else{
		for(i = 0;i < size;i++)
		{
			ListNode_t *node = nodeCreate(atoi(data[i]));
			if(NULL == node )
			{
				ret = RET_ERR;
			}
			if(RET_ERR == listAddToTail(list,node))
			{
				ret = RET_ERR;
			}
		}
	}
	return ret;
}

int main(int argc,char* argv[])
{
	char *help = "findKthToTail <list size> <data list ...> <Kth>";
	int listSize = 0;
	int kth = 0;
	int i = 0;
	List_t *list = NULL;
	ListNode_t *nodeFound= NULL;
	// 判断命令行参数是否满足最小个数
	if( CMD_PARAM_MIN_NUM > argc ) 
	{
		printf("too few params.\n");
		printf("%s\n",help);
		return RET_ERR;
	}
	
	// 根据listSize 判断参数个数是否满足
	listSize = atoi(argv[1]);
	if(listSize <= 0)
	{
		printf("list size wrong\n");
		return RET_ERR;
	}
	else if(listSize + 3 > argc)
	{
		printf("too few params.\n");
		printf("%s\n",help);
		return RET_ERR;
	}
	else if(listSize + 3 < argc)
	{
		printf("too many params.\n");
		printf("%s\n",help);
		return RET_ERR;
	}
	
	// 判断kth是否为负数
	kth = atoi(argv[argc - 1]);
	if(kth < 0)
	{
		printf("kth wrong\n");
		return RET_ERR;
	}
	// 创建list
	list = listCreate();
	if(NULL == list)
	{
		printf("list create error.\n");
		return RET_ERR;
	}
	//根据命令行参数给list添加数据
	if(RET_ERR == createTestList(list,listSize,&argv[2]))
	{
		// 创建失败，删除list
		listFree(list);
		list = NULL;
		return RET_ERR;
	}
	
	listPrint(list);
	
	// 查找倒数第k个
	nodeFound = findKthToTail(list->head,kth);
	if(NULL == nodeFound)
	{
		printf("find error\n");
		return RET_ERR;
	}
	printf("node find :%d\n",nodeFound->m_nKey);
	
	// 运行结束释放列表
	listFree(list);
	list = NULL;
	return RET_OK;
}
