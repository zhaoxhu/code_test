#include"JudgeIp.h"
/********************************************/
/***********函数名：InputIp******************/
/***********函数入口参数：数组***************/
/***********函数返回值：输入的个数***********/
/***********函数功能：输入和计算输入个数*****/
/********************************************/
static  unsigned int InputIp(char *ArrIp)//静态只能本.c使用
{
	char InputChar = 0;
	unsigned int IpIndex = 0;
	while((InputChar = getchar()) != '\n')
	{
		ArrIp[IpIndex] = InputChar;
		IpIndex++;
	}
	return IpIndex;//输入的个数
}
/********************************************/
/***********函数名：JudgeIp******************/
/***********函数入口参数：数组***************/
/***********函数返回值：标志真假*************/
/***********函数功能：判断输入的IP地址真假***/
/********************************************/
int JudgeIp(char *Ip)
{
	int dot = 0;
	int section = 0;
	if( '.' == *Ip)
	{
		return 0;
	}
	if('0' == *Ip)
	{
		return 0;
	}
	while(*Ip)
	{
		if('.' == *Ip)
		{
			if('.' == *(Ip+1))
			{
				return 0;
			}
			dot++;
			if(dot>3)
			{
				return 0;
			}
			if(section >= 0 && section <=255)
            { 
                section = 0; 
            }else{ 
                return 0; 
            } 
		}
		else if(*Ip >= '0' && *Ip <= '9')
        { 
            section = section * 10 + (*Ip - '0'); 
        }
		else
		{ 
            return 0; 
        } 
        Ip++;    
	}
	if(section >= 0 && section <=255)
    { 
       if(3 == dot)
        {
			return 1;//正确
        }
    } 
	else
	{
		return 0;//错误
	}
}
/***************************************************/
/***********函数名：strToiInt***********************/
/***********函数入口参数：IP地址和数组***************/
/***********函数返回值：void************************/
/***********函数功能：将字符IP装换成整数放到数组里***/
/*************************************************/
void StrToiInt(char *Ip,int *iArr)
{
	char temp[4] = {0};
	int IndexTemp = 0;
	int IndexiArr = 0;
	while(*Ip)
	{
		if('.' != *Ip)
		{
			temp[IndexTemp] = *Ip;
			IndexTemp++;
			Ip++;
		}
		else
		{
			iArr[IndexiArr] = atoi(temp);
			memset(temp,0,sizeof(temp));
			IndexTemp = 0;
			IndexiArr++;
			Ip++;
		}
	}
	iArr[IndexiArr] = atoi(temp);//将最后一个IP的段转换
}
/***************************************************/
/***********函数名：CheckNetSegment*****************/
/***********函数入口参数：IP地址和子网掩码***********/
/***********函数返回值：int标志不同的含义************/
/***********函数功能：判断IP1和IP2是否为同一个网段***/
/*************************************************/
int  CheckNetSegment(char *mask,char *Ip1,char *Ip2)
{
	int index = 0;
	int MaskArr[4] = {0};
	int IpArr1[4] = {0};
	int IpArr2[4] = {0};
	if(((JudgeIp(mask))&&(JudgeIp(Ip1))&&(JudgeIp(Ip2))) == 0)
	{
		return 1;//格式错误
	}
	StrToiInt(mask,MaskArr);
	StrToiInt(Ip1,IpArr1);
	StrToiInt(Ip2,IpArr2);
	for(;index<4;index++)
	{
		if((MaskArr[index]&IpArr1[index]) == (MaskArr[index]&IpArr2[index]))
		{
			return 0;//属于同一个子网络
		}
		else
		{
			return 2;//不属于同一个网络
		}
	}

}
/********************************************/
/***********函数名：main*********************/
/***********函数入口参数：无*****************/
/***********函数返回值：int类型**************/
/***********函数功能：程序的入口*************/
/********************************************/
int main()
{
	int iJudgeIp = 0;
	int MaskArr[MAX_INPUT] = {0};
	int IpArr1[MAX_INPUT] = {0};
	int IpArr2[MAX_INPUT] = {0};
	printf("请您输入要判断的mask地址：");
	InputIp(MaskArr);
	printf("请您输入要判断的IP1地址：");
	InputIp(IpArr1);
	printf("请您输入要判断的IP2地址：");
	InputIp(IpArr1);
	iJudgeIp = CheckNetSegment(MaskArr,IpArr1,IpArr2);
	printf("%d",iJudgeIp);
	system("pause");
	return 0;
}
