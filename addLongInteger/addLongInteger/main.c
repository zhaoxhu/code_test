#include"AddLongInteger.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/***********************************************************/
/************��������inputArray*****************************/
/************��ڲ����������ַ����ͱ������ַ����ͽ��*********/
/************����ֵ���ж��Ƿ�ɹ�***************************/
/************�������ܣ�����*********************************/
/**********************************************************/
int inputArrayM(char **addend,char **augend,char **result)
{
	char ch = 0;
	int countAddend = 0;
	int countAugend = 0;
	printf("�����������");
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
	printf("�����뱻������");
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
��������main
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
		printf("�������\n");
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