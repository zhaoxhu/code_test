#include<stdio.h>
#include<stdlib.h>
void strToInts(char *ipAdd, int* iArr )//将ip地址转换成整型，存储到iArr中
{
	char temp[4] = {0};
	char *p = ipAdd;
	int i =0;
	int j= 0;
	while (*p != '\0')//将前三个用'.'分割的字符串转换成整数
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
	iArr[i] = atoi(temp);//将最后一段字符串转换成整数

}

int IsSameSubNetwork(char * pcIp1, char * pcIp2, char * pcSubNetworkMask)
{
    /*在这里实现功能*/
	int i = 0;
	int Ip1[4]={0};
	int Ip2[4] = {0};
	int mask[4] ={0};
	strToInts(pcIp1, Ip1);
	strToInts(pcIp2, Ip2);
	strToInts(pcSubNetworkMask, mask);
	for (; i < 4; ++i)
	{
		if ((Ip1[i]&mask[i]) != (Ip2[i] &mask[i]))//子网号码如果有不同的，则两个Ip地址不在同一子网
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