#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
判断回文
*/
int statckJudge(char *arr,int size)
{
	char temp[100] = {0};//存放前半部分
	int index = 0;
	int top = 0;//栈初始值
	int next = 0;//后半部分下标
	int mid = size/2 - 1;//中间位置
	//检测传进的指针是否为空
	if ( NULL == arr)
	{
		return -1;
	}
	//将字符串的前半部分放到temp中
	for ( ; index <= mid ;index++ )
	{
		temp[++top] = arr[index];
	}
	//求取后半部分起始下标
	if ( 0 == size%2 )
	{
		next = mid+1;
	}
	else
	{
		next = mid+2;
	}
	//判断是否为回文
	for (index = next;index < size;index++)
	{
		if ( temp[top] != arr[index] )
		{
			return -1;
		}
		top--;
	}
	if ( 0 == top )//说明全部字符成立，成立则为回文。
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int sizeOfArr = 0;//输入字符串长度
	int ret = 0;//接收函数返回值
	char inputArr[100] = {0};//装载回文
	printf("请输入要判断的字符串：");
	gets(inputArr);//获取输入
	sizeOfArr = strlen(inputArr);//求取输入字符串长度
	ret = statckJudge(inputArr,sizeOfArr);//接收返回值
	//判断返回值，并做相应输出
	if ( 0 == ret)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	system("pause");//让它停下来
	return 0;
}