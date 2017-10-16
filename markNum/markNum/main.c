#include<stdio.h>
#include"markNum.h"
#include<stdlib.h>
/*
字符串的输入
*/

static int inputArrayM(char **sorNumber,char **desNumber)
{
	char ch = 0;
	int count = 0;
	printf("请输入字符串：");
	*sorNumber = (char *)malloc(sizeof(char));
	if(NULL == *sorNumber)
	{
		return FALSE;
	}
	while((ch = getchar()) != '\n')
	{
		
		*(*sorNumber+count) = ch;
		count++;
		*sorNumber = (char *)realloc(*sorNumber,(count+1)*sizeof(char));
		if(NULL == *sorNumber)
		{
			return FALSE;
		}
	}
	*((*sorNumber)+count) = '\0';

	*desNumber = (char *)malloc(sizeof(char)*4*count);
	return TURE;
}
/*
主函数，程序的入口
*/
int main()
{
	char *sorNumber = NULL;
	char *desNumber = NULL;
	inputArrayM(&sorNumber,&desNumber);
	markNum(sorNumber,desNumber);
	printf("%s",desNumber);
	printf("\n");
	system("pause");
	return 0;
}