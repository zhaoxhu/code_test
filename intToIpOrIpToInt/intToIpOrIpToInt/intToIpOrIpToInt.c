#include "intToIpOrIpToInt.h"
#include <stdlib.h>
/*
����ת����IP��ַ
*/
int intToIp(int number,int *ip)
{
	//int Arr[32] = 0;
	//intToArr(number,Arr);
	*ip = (number >> 24) & 0xff;  //�����8λ
	*(ip+1) = (number >> 16) & 0xff;//�θ�8λ
	*(ip+2) = (number >> 8) & 0xff;//�δθ�8λ
	*(ip+3) = number & 0xff;//��8λ
	return TURE;
}
/*
��ʾ����ת����IP��ַ
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
ip��ַת��������
*/
int ipToInt(char *ip)
{
	int retNumber = 0; //ת���õ�����
	int i = 8;//��Ҫ�ƶ���λ��������������32.
	int index = 0;
	char temp[4] = {0};//���ÿ���ڵ�
	while(*ip)
	{
		while(('.' != *ip)&&('\0' != *ip))//��ȡÿ���ڵ����������ŵ�����temp�С�
		{
			temp[index] = *ip;
			index++;
			ip++;
		}
		temp[index] = '\0';
		retNumber = (atoi(temp) << (32-i))+retNumber;//���ÿ���ڵ㲢��ת������������8λ
		ip++;
		i += 8;
		index = 0;
	}
	return retNumber;
}