#include"JudgeIp.h"
/********************************************/
/***********��������InputIp******************/
/***********������ڲ���������***************/
/***********��������ֵ������ĸ���***********/
/***********�������ܣ�����ͼ����������*****/
/********************************************/
static  unsigned int InputIp(char *ArrIp)//��ֻ̬�ܱ�.cʹ��
{
	char InputChar = 0;
	unsigned int IpIndex = 0;
	while((InputChar = getchar()) != '\n')
	{
		ArrIp[IpIndex] = InputChar;
		IpIndex++;
	}
	return IpIndex;//����ĸ���
}
/********************************************/
/***********��������JudgeIp******************/
/***********������ڲ���������***************/
/***********��������ֵ����־���*************/
/***********�������ܣ��ж������IP��ַ���***/
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
			return 1;//��ȷ
        }
    } 
	else
	{
		return 0;//����
	}
}
/***************************************************/
/***********��������strToiInt***********************/
/***********������ڲ�����IP��ַ������***************/
/***********��������ֵ��void************************/
/***********�������ܣ����ַ�IPװ���������ŵ�������***/
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
	iArr[IndexiArr] = atoi(temp);//�����һ��IP�Ķ�ת��
}
/***************************************************/
/***********��������CheckNetSegment*****************/
/***********������ڲ�����IP��ַ����������***********/
/***********��������ֵ��int��־��ͬ�ĺ���************/
/***********�������ܣ��ж�IP1��IP2�Ƿ�Ϊͬһ������***/
/*************************************************/
int  CheckNetSegment(char *mask,char *Ip1,char *Ip2)
{
	int index = 0;
	int MaskArr[4] = {0};
	int IpArr1[4] = {0};
	int IpArr2[4] = {0};
	if(((JudgeIp(mask))&&(JudgeIp(Ip1))&&(JudgeIp(Ip2))) == 0)
	{
		return 1;//��ʽ����
	}
	StrToiInt(mask,MaskArr);
	StrToiInt(Ip1,IpArr1);
	StrToiInt(Ip2,IpArr2);
	for(;index<4;index++)
	{
		if((MaskArr[index]&IpArr1[index]) == (MaskArr[index]&IpArr2[index]))
		{
			return 0;//����ͬһ��������
		}
		else
		{
			return 2;//������ͬһ������
		}
	}

}
/********************************************/
/***********��������main*********************/
/***********������ڲ�������*****************/
/***********��������ֵ��int����**************/
/***********�������ܣ���������*************/
/********************************************/
int main()
{
	int iJudgeIp = 0;
	int MaskArr[MAX_INPUT] = {0};
	int IpArr1[MAX_INPUT] = {0};
	int IpArr2[MAX_INPUT] = {0};
	printf("��������Ҫ�жϵ�mask��ַ��");
	InputIp(MaskArr);
	printf("��������Ҫ�жϵ�IP1��ַ��");
	InputIp(IpArr1);
	printf("��������Ҫ�жϵ�IP2��ַ��");
	InputIp(IpArr1);
	iJudgeIp = CheckNetSegment(MaskArr,IpArr1,IpArr2);
	printf("%d",iJudgeIp);
	system("pause");
	return 0;
}
