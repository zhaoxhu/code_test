#include"main.h"
#include"encryptUnencrypt.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*****************************************************************************/
/*��������inputString*/
/*������ڲ�����������ַ���*/
/*��������ֵ����ʶ�����Ƿ�ɹ����*/
/*�������ܣ��������*/
/*****************************************************************************/
int inputString(char *encryptArray,char *unencryptArray)
{
	int ch = 0;
	if((NULL == encryptArray) && (NULL == unencryptArray))
	{
		return FALSE;
	}
	printf("������Ҫ���ܵ��ַ�����");
	while((ch = getchar()) != '\n')
	{
		*encryptArray = ch;
		encryptArray++;
	}
	*encryptArray = '\0';
	printf("������Ҫ���ܵ��ַ�����");
	while((ch = getchar()) != '\n')
	{
		*unencryptArray = ch;
		unencryptArray++;
	}
	*unencryptArray = '\0';
	return TURE;
}


/*****************************************************************************/
/*��������main*/
/*������ڲ�������*/
/*��������ֵ��0*/
/*�������ܣ���������*/
/*****************************************************************************/
int main()
{
	char encryptArray[ENCRYPT_ARR] = {0};//Ҫ���ܵĵ��ַ�����������
	char encryptResult[ENCRYPT_ARR] = {0};//���ܺõ��ַ�������
	char unencryptArray[UNENCRYPT_ARR] = {0};//Ҫ���ܵ��ַ�����������
	char unencrypResult[UNENCRYPT_ARR] = {0};//���ܺõ��ַ�����
	inputString(encryptArray,unencryptArray);//�����ַ���
	Encrypt(encryptArray,encryptResult);//����
	unEncrypt(unencrypResult,unencryptArray);//����
	printf("%s",encryptResult);//�������
	printf("\n");
	printf("%s",unencrypResult);//�������
	printf("\n");
	system("pause");
	return 0;
}