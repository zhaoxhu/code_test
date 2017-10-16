#include"arithmeticProgression.h"
/*
等差数列求前number项和
*/
int arithmeticProgression(int number,int *result)
{
	int index = 0;
	int itemN = FIRSTITEM;
	*result = 0;
	if((number <= 0)||(number > 2147483647)) //检测入口参数
	{
		return FALSE;
	}
	for(;index < number;index++)
	{
		*result += itemN;
		itemN += DIFFER;
	}
	if(*result > 2147483647)//超出int范围
	{
		return FALSE;
	}
	return TURE;
}