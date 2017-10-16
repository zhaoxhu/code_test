#include<stdio.h>
#include<stdlib.h>
void strToInts(char *ipAdd, int* iArr )//��ip��ַת�������ͣ��洢��iArr��
{
	char temp[4] = {0};
	char *p = ipAdd;
	int i =0;
	int j= 0;
	while (*p != '\0')//��ǰ������'.'�ָ���ַ���ת��������
	{
		if (*p != '.')
		{
			temp [j] = *p;
			j++;
			++p;
		}
		else
		{
			iArr[i] = atoi(temp);
			memset(temp,0,sizeof(temp));
			j = 0;
			i++;
			++p;
		}
	}
	iArr[i] = atoi(temp);//�����һ���ַ���ת��������

}

int IsSameSubNetwork(char * pcIp1, char * pcIp2, char * pcSubNetworkMask)
{
    /*������ʵ�ֹ���*/
	int i = 0;
	int Ip1[4]={0};
	int Ip2[4] = {0};
	int mask[4] ={0};
	strToInts(pcIp1, Ip1);
	strToInts(pcIp2, Ip2);
	strToInts(pcSubNetworkMask, mask);
	for (; i < 4; ++i)
	{
		if ((Ip1[i]&mask[i]) != (Ip2[i] &mask[i]))//������������в�ͬ�ģ�������Ip��ַ����ͬһ����
		{
			return 0;
		}
	}
    return 1;
}


int main()
{
	printf("%d",IsSameSubNetwork("192.168.0.1", "192.168.0.254", "255.255.255.0"));
	system("pause");
	return 0;
}