#include"AddLongInteger.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/***********************************************************/
/************函数名：inputArray*****************************/
/************入口参数：加数字符串和被加数字符串和结果*********/
/************返回值：判断是否成功***************************/
/************函数功能：输入*********************************/
/**********************************************************/
int inputArrayM(char **addend,char **augend,char **result)
{
	char ch = 0;
	int countAddend = 0;
	int countAugend = 0;
	printf("请输入加数：");
	*addend = (char *)malloc(sizeof(char));
	if(NULL == *addend)
	{
		return FALSE;
	}
	while((ch = getchar()) != '\n')
	{
		
		*(*addend+countAddend) = ch;
		countAddend++;
		*addend = (char *)realloc(*addend,(countAddend+1)*sizeof(char));
		if(NULL == *addend)
		{
			return FALSE;
		}
	}
	*((*addend)+countAddend) = '\0';
	printf("请输入被加数：");
	*augend = (char *)malloc(sizeof(char));
	if(NULL == *addend)
	{
		return FALSE;
	}
	while((ch = getchar()) != '\n')
	{
		
		*(*augend+countAugend) = ch;
		countAugend++;
		*augend = (char *)realloc(*augend,(countAugend+1)*sizeof(char));
		if(NULL == *addend)
		{
			return FALSE;
		}
	}
	*((*augend)+countAugend) = '\0';
	if(countAugend > countAddend)
	{
		*result = (char *)malloc((countAugend+3)*sizeof(char));
	}
	else
	{
		*result = (char *)malloc((countAddend+3)*sizeof(char));
	}
	return TURE;
}
/*
程序的入口main
*/
int main()
{
	int index = 0;
	char *addend = NULL;
	char *augend = NULL;
	char *result = NULL;
	inputArrayM(&addend,&augend,&result);
	if(FALSE == AddLongInteger(addend,augend,result))
	{
		printf("计算出错\n");
		return 0;
	}
	index = strlen(result)-1;

	for(;index>=0;index--)
	{
		printf("%c",result[index]);
	}
	printf("\n");
	system("pause");
	free(addend);
	free(augend);
	free(result);
	return 0;
}