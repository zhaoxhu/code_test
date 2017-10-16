#include"AddLongInteger.h"
#include<string.h>
/***********************************************************/
/************��������AddCharInerger*************************/
/************��ڲ����������ַ��ͱ������ַ�*****************/
/************����ֵ����ӽ��*******************************/
/************�������ܣ�����������ӽ��*********************/
/***********************************************************/
static int AddCharInerger(char addend,char augend)
{
	int  ret = (addend -'0') + (augend - '0');
	return ret;

}
/***********************************************************/
/************��������AddLongInteger*************************/
/************��ڲ����������ַ����ͱ������ַ���*************/
/************����ֵ����ӽ��*******************************/
/************�������ܣ����������������*********************/
/***********************************************************/
int AddLongInteger(char *addend,char *augend,char *result)
{
	int index = 0;
	int tmp = 0;
	int sizeAddend = strlen(addend);
	int sizeAugend = strlen(augend);
	int tempNumber = sizeAddend;
	//�ж��Ƿ���ȷ����
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
		//�ж��Ƿ�Ҫ��λ
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
		//�ж��Ƿ�Խ��
		if(sizeAddend == 0)
		{
			sizeAddend += 1;
			addend[sizeAddend-1] = '0';
		}
		sizeAugend--;
		//�ж��Ƿ�Խ��
		if(sizeAugend == 0)
		{
			sizeAugend += 1;
			augend[sizeAugend-1] = '0';
		}
		tempNumber--;
	}
	//����Ƿ��н�λ
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