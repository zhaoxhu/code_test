#include "intToIpOrIpToInt.h"
#include <stdlib.h>
/*
整数转换成IP地址
*/
int intToIp(int number,int *ip)
{
	//int Arr[32] = 0;
	//intToArr(number,Arr);
	*ip = (number >> 24) & 0xff;  //请最高8位
	*(ip+1) = (number >> 16) & 0xff;//次高8位
	*(ip+2) = (number >> 8) & 0xff;//次次高8位
	*(ip+3) = number & 0xff;//低8位
	return TURE;
}
/*
显示整数转换成IP地址
*/
void displayIntToIp(int *ip)
{
	int index = 0;
	for(;index<3;index++)
	{
		printf("%d",ip[index]);
		printf(".");
	}
	printf("%d",ip[index]);

}
/*
ip地址转换成整数
*/
int ipToInt(char *ip)
{
	int retNumber = 0; //转换好的整数
	int i = 8;//需要移动的位数被减数，减数32.
	int index = 0;
	char temp[4] = {0};//存放每个节点
	while(*ip)
	{
		while(('.' != *ip)&&('\0' != *ip))//求取每个节点的数并将其放到数组temp中。
		{
			temp[index] = *ip;
			index++;
			ip++;
		}
		temp[index] = '\0';
		retNumber = (atoi(temp) << (32-i))+retNumber;//存放每个节点并将转换成整数左移8位
		ip++;
		i += 8;
		index = 0;
	}
	return retNumber;
}