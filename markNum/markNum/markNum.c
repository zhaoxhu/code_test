#include"markNum.h"
#include<string.h>
/*
ͨ���ж�sorNumber�е����֣������ֵ�ǰ�󶼼�*��desNumber����Ӻ�*���ַ���
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