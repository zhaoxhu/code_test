#include "pointGame24.h"
/*****************************����ŷ���******************************/
char mark[4]={'+','-','*','/'};


/*����24����Ϸ���Է�Ϊ5��ģʽ,���������ż���ʲô�ط������⡣���Է�Ϊ��������*/

/*****************************************************************************/
/* 1. ((a b) c) d 2. (a (b c)) d 3. a (b (c d)) 4. a ((b c) d) 5. (a b) (c d)*/
/*****************************************************************************/


/*
�м���㣬�������㣬���ж� + - * /
��������5��ģʽ�м����
*/
static float calculateTwo(float x,float y,int mark)
{
	switch(mark)
	{
	case 0:return x+y;
	case 1:return x-y;
	case 2:return x*y;
	case 3:return x/y;
	}
	return 0.0;
}
/*
���м����ģʽ�ǣ�((a b) c) d
*/
static float calculateModeOne(float a,float b,float c,float d,int mark1,int mark2,int mark3)
{
	float value1,value2,value3;
	value1=calculateTwo(a,b,mark1);
	value2=calculateTwo(value1,c,mark2);
	value3=calculateTwo(value2,d,mark3);
	return value3;
}
/*
���м����ģʽ�ǣ�(a (b c)) d
*/
static float calculateModeTwo(float a,float b,float c,float d,int mark1,int mark2,int mark3)
{
	float value1,value2,value3;
	value1=calculateTwo(b,c,mark2);
	value2=calculateTwo(a,value1,mark1);
	value3=calculateTwo(value2,d,mark3);
	return value3;
}
/*
���м����ģʽ�ǣ�a (b (c d))
*/
static float calculateModeThree(float a,float b,float c,float d,int mark1,int mark2,int mark3)
{
	float value1,value2,value3;
	value1=calculateTwo(c,d,mark3);
	value2=calculateTwo(b,value1,mark2);
	value3=calculateTwo(a,value2,mark1);
	return value3;
}
/*
���м����ģʽ�ǣ�a ((b c) d)
*/
static float calculateModeFour(float a,float b,float c,float d,int mark1,int mark2,int mark3)
{
	float value1,value2,value3;
	value1=calculateTwo(b,c,mark2);
	value2=calculateTwo(value1,d,mark3);
	value3=calculateTwo(a,value2,mark1);
	return value3;
}
/*
���м����ģʽ�ǣ�(a b) (c d)
*/
static float calculateModeFive(float a,float b,float c,float d,int mark1,int mark2,int mark3)
{
	float value1,value2,value3;
	value1=calculateTwo(a,b,mark1);
	value2=calculateTwo(c,d,mark3);
	value3=calculateTwo(value1,value2,mark2);
	return value3;
}
/*
���㴫�������ĸ�ֵ���������ܷ�õ�24
*/
int pointGame24(float a,float b,float c,float d)
{
	int mark1,mark2,mark3;
	for(mark1=0;mark1<4;mark1++)
	{
		for(mark2=0;mark2<4;mark2++)
		{
			for(mark3=0;mark3<4;mark3++)
			{
				if(calculateModeOne(a,b,c,d,mark1,mark2,mark3)==24)
				{
					return TURE;
				}
				if(calculateModeTwo(a,b,c,d,mark1,mark2,mark3)==24)
				{	
					return TURE;
				}
				if(calculateModeThree(a,b,c,d,mark1,mark2,mark3)==24)
				{
					return TURE;
				}
				if(calculateModeFour(a,b,c,d,mark1,mark2,mark3)==24)
				{
					return TURE;
				}
				if(calculateModeFive(a,b,c,d,mark1,mark2,mark3)==24)
				{
					return TURE;
				}
			}
		}
	}
	return FALSE;
}