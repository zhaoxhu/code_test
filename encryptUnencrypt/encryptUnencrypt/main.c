#include"main.h"
#include"encryptUnencrypt.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*****************************************************************************/
/*函数名：inputString*/
/*函数入口参数：输入的字符串*/
/*函数返回值：标识函数是否成功完成*/
/*函数功能：输入接收*/
/*****************************************************************************/
int inputString(char *encryptArray,char *unencryptArray)
{
	int ch = 0;
	if((NULL == encryptArray) && (NULL == unencryptArray))
	{
		return FALSE;
	}
	printf("请输入要加密的字符串：");
	while((ch = getchar()) != '\n')
	{
		*encryptArray = ch;
		encryptArray++;
	}
	*encryptArray = '\0';
	printf("请输入要解密的字符串：");
	while((ch = getchar()) != '\n')
	{
		*unencryptArray = ch;
		unencryptArray++;
	}
	*unencryptArray = '\0';
	return TURE;
}


/*****************************************************************************/
/*函数名：main*/
/*函数入口参数：无*/
/*函数返回值：0*/
/*函数功能：程序的入口*/
/*****************************************************************************/
int main()
{
	char encryptArray[ENCRYPT_ARR] = {0};//要加密的的字符串接收数组
	char encryptResult[ENCRYPT_ARR] = {0};//加密好的字符串数组
	char unencryptArray[UNENCRYPT_ARR] = {0};//要解密的字符串接收数组
	char unencrypResult[UNENCRYPT_ARR] = {0};//解密好的字符数组
	inputString(encryptArray,unencryptArray);//输入字符串
	Encrypt(encryptArray,encryptResult);//加密
	unEncrypt(unencrypResult,unencryptArray);//解密
	printf("%s",encryptResult);//输出解密
	printf("\n");
	printf("%s",unencrypResult);//输出解密
	printf("\n");
	system("pause");
	return 0;
}