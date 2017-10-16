#include"AddLongInteger.h"
#include<string.h>
/***********************************************************/
/************函数名：AddCharInerger*************************/
/************入口参数：加数字符和被加数字符*****************/
/************返回值：相加结果*******************************/
/************函数功能：求两个数相加结果*********************/
/***********************************************************/
static int AddCharInerger(char addend,char augend)
{
	int  ret = (addend -'0') + (augend - '0');
	return ret;

}
/***********************************************************/
/************函数名：AddLongInteger*************************/
/************入口参数：加数字符串和被加数字符串*************/
/************返回值：相加结果*******************************/
/************函数功能：求两个超长数相加*********************/
/***********************************************************/
int AddLongInteger(char *addend,char *augend,char *result)
{
	int index = 0;
	int tmp = 0;
	int sizeAddend = strlen(addend);
	int sizeAugend = strlen(augend);
	int tempNumber = sizeAddend;
	//判断是否正确输入
	if((NULL == addend)&&(NULL == augend)&&(NULL == result))
	{
		return FALSE;
	}
	if(tempNumber <= sizeAugend)
	{
		tempNumber = sizeAugend;
	}
	while(tempNumber)
	{
		int temp = AddCharInerger(addend[sizeAddend-1],augend[sizeAugend-1])+tmp;
		//判断是否要进位
		if(temp >= 10)
		{
			result[index] = temp%10 + '0';
			tmp = temp/10;
		}
		else
		{
			tmp = 0;
			result[index] = temp + '0';
		}
		index++;
		sizeAddend--;
		//判断是否越界
		if(sizeAddend == 0)
		{
			sizeAddend += 1;
			addend[sizeAddend-1] = '0';
		}
		sizeAugend--;
		//判断是否越界
		if(sizeAugend == 0)
		{
			sizeAugend += 1;
			augend[sizeAugend-1] = '0';
		}
		tempNumber--;
	}
	//最后是否有进位
	if(tmp > 0)
	{
	    result[index] = (tmp + '0');
		result[index+1] = '\0';

	}
	else
	{
		result[index] = '\0';
	}
	return TURE;
}