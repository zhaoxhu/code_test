#include"JudgeIp.h"
#define TURE 1
#define FALSE 0
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
		return FALSE;
	}
	while(*Ip)
	{
		if('.' == *Ip)
		{
			if('.' == *(Ip+1))
			{
				return FALSE;
			}
			dot++;
			if(dot>3)
			{
				return FALSE;
			}
			if(section >= 0 && section <=255)
            { 
                section = 0; 
            }else{ 
                return FALSE; 
            } 
		}
		else if(*Ip >= '0' && *Ip <= '9')
        { 
            section = section * 10 + (*Ip - '0'); 
        }
		else
		{ 
            return FALSE; 
        } 
        Ip++;    
	}
	if(section >= 0 && section <=255)
    { 
       if(3 == dot)
        {
			return TURE;
        }
    } 
	else
	{
		return FALSE;
	}
}
