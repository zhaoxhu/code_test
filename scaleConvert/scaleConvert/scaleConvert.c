#include"scaleConvert.h"

/***********************************************************/
/************函数名：inputAndDetection**********************/
/************入口参数：16进制字符串*************************/
/************返回值：int类型********************************/
/************函数功能：输入十六进制数***********************/
/***********************************************************/
static int inputData(char *scaleArray16)
{
	int index = 0;
	char ch = 0;
	if(NULL == scaleArray16)
	{
		return FALSE;
	}
	printf("请输入要转换的16进制数：");
    while((ch = getchar()) != '\n')
	{
		scaleArray16[index] = ch;
		index++;
	}
	scaleArray16[index] = '\0';
	return TURE;
}
/***********************************************************/
/************函数名：scaleConvert***************************/
/************入口参数：16进制字符串*************************/
/************返回值：10进制数*******************************/
/************函数功能：将一个16进制字符转换成十进制*********/
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
/************函数名：scaleConvert***************************/
/************入口参数：16进制字符串*************************/
/************返回值：10进制数*******************************/
/************函数功能：16进制转10进制***********************/
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
	return scaleNumber10;//返回的十进制数
}
/***********************************************************/
/************函数名：main***********************************/
/************入口参数：无***********************************/
/************返回值：0**************************************/
/************函数功能：程序的如口***************************/
/***********************************************************/
int main()
{
	int index = 0;
	int sizeArray16 = 0;
	int scaleNumber10 = 0;
	char scaleArray16[MAX_ARRAY] = {0};
	char scaleArray10[MAX_ARRAY] = {0};
	inputData(scaleArray16);//输入16进制数
	sizeArray16 = strlen(scaleArray16)-1;//16进制字符串的长度-1
	scaleNumber10 = scaleConvert(scaleArray16,sizeArray16);//转换
	printf("%s",itoa(scaleNumber10,scaleArray10,10));
	printf("\n");
	system("pause");
	return 0;
}