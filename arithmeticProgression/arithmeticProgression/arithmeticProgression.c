#include"arithmeticProgression.h"
/*
�Ȳ�������ǰnumber���
*/
int arithmeticProgression(int number,int *result)
{
	int index = 0;
	int itemN = FIRSTITEM;
	*result = 0;
	if((number <= 0)||(number > 2147483647)) //�����ڲ���
	{
		return FALSE;
	}
	for(;index < number;index++)
	{
		*result += itemN;
		itemN += DIFFER;
	}
	if(*result > 2147483647)//����int��Χ
	{
		return FALSE;
	}
	return TURE;
}