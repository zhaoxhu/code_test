#ifndef _JUDGEIP_
#define _JUDGEIP_
/*************************��Ҫ�ӵ�ͷ�ļ�***************************/
#include<stdio.h>
#include<stdlib.h>


#define MAX_INPUT 100  //����ܽ��յ�����

/*************************��������*********************************/
int JudgeIp(char *Ip);//�ж������IP��ַ�Ƿ����

void StrToiInt(char *Ip,int *iArr); //��IP��ַת����4������

int  CheckNetSegment(char *mask,char *Ip1,char *Ip2);//�ж�Ip1��IP2�Ƿ�Ϊͬһ������
#endif   //JUDGEIP