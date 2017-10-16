#include"markNum.h"
#include<string.h>
/*
通过判断sorNumber中的数字，给数字的前后都加*。desNumber保存加好*的字符串
*/
int markNum(char *sorNumber,char *desNumber)
{
	int indexSorNumber = 0;
	int indexDesNumber = 0;
	int sizeSorNumber = strlen(sorNumber);
	if((NULL ==sorNumber)&&(NULL == desNumber))
	{
		return FALSE;
	}
	while(sorNumber[indexSorNumber])
	{
		if((sorNumber[indexSorNumber] >= '0')&&(sorNumber[indexSorNumber] <= '9'))
		{
			desNumber[indexDesNumber] = '*';
			indexDesNumber++;
			while((sorNumber[indexSorNumber] >= '0')&&(sorNumber[indexSorNumber] <= '9'))
			{
				desNumber[indexDesNumber] = sorNumber[indexSorNumber];
				indexDesNumber++;
				indexSorNumber++;
			}
			desNumber[indexDesNumber] = '*';
			indexDesNumber++;
		}
		else
		{
			desNumber[indexDesNumber] = sorNumber[indexSorNumber];
			indexDesNumber++;
			indexSorNumber++;
		}
	}
	desNumber[indexDesNumber] = '\0';
	return TURE;
}