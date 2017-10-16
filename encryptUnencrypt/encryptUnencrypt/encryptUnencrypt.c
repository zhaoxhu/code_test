/*============================= Include Files ===============================*/
#include"encryptUnencrypt.h"
#include<string.h>

/*****************************************************************************/
/*函数名：oneCharEncrypt*/
/*函数入口参数：要加密的数组*/
/*函数返回值：标识函数是否成功完成*/
/*函数功能：实现对一个字符串的加密*/
/*****************************************************************************/
static char oneCharEncrypt(char ch)
{
	if((ch >= 'a') && (ch <='z'))
	{
		ch -= 32;
		if('Z' == ch)
		{
			ch = 'a';
		}
		else
		{
			ch += 1;
		}
	}
	else if((ch >= 'A') && (ch <= 'Z'))
	{
		ch += 32;
		if('z' == ch)
		{
			ch = 'a';
		}
		else
		{
			ch += 1;
		}
	}
	else if((ch >= '0') && (ch <= '9'))
	{
		if('9' == ch)
		{
			ch = '0';
		}
		else
		{
			ch += 1;
		}
		
	}
	else
	{
		return ch;
	}
	return ch;
}
/*****************************************************************************/
/*函数名：Encrypt*/
/*函数入口参数：加密和未加密两个数组*/
/*函数返回值：标识函数是否成功完成*/
/*函数功能：实现对字符串的加密*/
/*****************************************************************************/
int Encrypt(char aucPassword[], char aucResult[])
{
	int index = 0;
	//求取要加密数组长度
	int sizeArr = strlen(aucPassword);
	//依次加密
	for(;index < sizeArr;index++)
	{
		aucResult[index] = oneCharEncrypt(aucPassword[index]);  
	}
	return TURE;
}
/*****************************************************************************/
/*函数名：oneCharUnencrypt*/
/*函数入口参数：要解密的数组*/
/*函数返回值：标识函数是否成功完成*/
/*函数功能：实现对一个字符串的解密*/
/*****************************************************************************/
static char oneCharUnencrypt(char ch)
{
	if((ch >= 'a') && (ch <='z'))
	{
		ch -= 33;
	}
	else if((ch >= 'A') && (ch <= 'Z'))
	{
		ch += 31;
	}
	else if((ch >= '0') && (ch <= '9'))
	{
		if('0' == ch)
		{
			ch = '9';
		}
		else
		{
			ch -= 1;
		}	
	}
	else
	{
		return ch;
	}
	return ch;
}
/*****************************************************************************/
/*函数名：unEncrypt*/
/*函数入口参数：加密和未加密两个数组*/
/*函数返回值：标识函数是否成功完成*/
/*函数功能：实现对字符串的解密*/
/*****************************************************************************/
int unEncrypt(char result[], char password[])
{
	int index = 0;
	//解密字符串的长度
	int sizeArr = strlen(password);
	//依次解密
	for(;index < sizeArr;index++)
	{
		result[index] = oneCharUnencrypt(password[index]);
	}
	return TURE;
}