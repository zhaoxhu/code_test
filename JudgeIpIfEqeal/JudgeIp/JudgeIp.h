#ifndef _JUDGEIP_
#define _JUDGEIP_
/*************************需要加的头文件***************************/
#include<stdio.h>
#include<stdlib.h>


#define MAX_INPUT 100  //最大能接收的数组

/*************************函数声明*********************************/
int JudgeIp(char *Ip);//判断输入的IP地址是否合理

void StrToiInt(char *Ip,int *iArr); //将IP地址转换成4段整数

int  CheckNetSegment(char *mask,char *Ip1,char *Ip2);//判断Ip1和IP2是否为同一个网段
#endif   //JUDGEIP