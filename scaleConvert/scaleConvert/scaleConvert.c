#include"scaleConvert.h"

/***********************************************************/
/************��������inputAndDetection**********************/
/************��ڲ�����16�����ַ���*************************/
/************����ֵ��int����********************************/
/************�������ܣ�����ʮ��������***********************/
/***********************************************************/
static int inputData(char *scaleArray16)
{
	int index = 0;
	char ch = 0;
	if(NULL == scaleArray16)
	{
		return FALSE;
	}
	printf("������Ҫת����16��������");
    while((ch = getchar()) != '\n')
	{
		scaleArray16[index] = ch;
		index++;
	}
	scaleArray16[index] = '\0';
	return TURE;
}
/***********************************************************/
/************��������scaleConvert***************************/
/************��ڲ�����16�����ַ���*************************/
/************����ֵ��10������*******************************/
/************�������ܣ���һ��16�����ַ�ת����ʮ����*********/
/***********************************************************/
static int byteScaleConvert(char oneChar)   
{
	int returnValue = 0;
	if((oneChar >= '0')&&(oneChar <= '9'))
	{
		returnValue = oneChar - '0';
	}
	else if((oneChar >= 'a')&&(oneChar <= 'f'))
	{
		returnValue = oneChar - 87;
	}
	else if((oneChar >= 'A')&&(oneChar <= 'F'))
	{
		returnValue = oneChar - 55;
	}
	return returnValue;
}
/***********************************************************/
/************��������scaleConvert***************************/
/************��ڲ�����16�����ַ���*************************/
/************����ֵ��10������*******************************/
/************�������ܣ�16����ת10����***********************/
/***********************************************************/
int scaleConvert(char *scaleArray16,int sizeArray)
{
	int scaleNumber10 = 0;
	int temp = sizeArray;
	if(NULL == scaleArray16)
	{
		return FALSE;
	}
	while(sizeArray>1)
	{
		scaleNumber10 += byteScaleConvert(scaleArray16[sizeArray])*pow(16,(temp-sizeArray));
		sizeArray--;
	}
	return scaleNumber10;//���ص�ʮ������
}
/***********************************************************/
/************��������main***********************************/
/************��ڲ�������***********************************/
/************����ֵ��0**************************************/
/************�������ܣ���������***************************/
/***********************************************************/
int main()
{
	int index = 0;
	int sizeArray16 = 0;
	int scaleNumber10 = 0;
	char scaleArray16[MAX_ARRAY] = {0};
	char scaleArray10[MAX_ARRAY] = {0};
	inputData(scaleArray16);//����16������
	sizeArray16 = strlen(scaleArray16)-1;//16�����ַ����ĳ���-1
	scaleNumber10 = scaleConvert(scaleArray16,sizeArray16);//ת��
	printf("%s",itoa(scaleNumber10,scaleArray10,10));
	printf("\n");
	system("pause");
	return 0;
}