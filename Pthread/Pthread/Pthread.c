#include <string.h>
#include <stdlib.h>
#include <stdio.h>   
#include <process.h>   
#include <windows.h>  
#define MAXHANDLE  3
char  g_write[1028]; //线程1,线程2,线程3按到顺序向该数组赋值
HANDLE g_hThreadEvent[3];
HANDLE handle[MAXHANDLE];
int g_Number;
//线程1函数   
unsigned int __stdcall ThreadFun1(PVOID pM)  
{  
    int uiNumber = *(int *)pM;
    int iLoop    = 0;
    g_Number = uiNumber;
    for (iLoop; iLoop < uiNumber; iLoop++)
    {
        //printf("this is thread 1: %s\n", g_write);
        WaitForSingleObject(g_hThreadEvent[0], INFINITE);
        strcat(g_write, "A");
        SetEvent(g_hThreadEvent[1]);
    }
    _endthreadex(0);
    return 0; 
} 
//线程2函数   
unsigned int __stdcall ThreadFun2(PVOID pM)  
{  
    int iLoop = 0;
    for (iLoop; iLoop < g_Number; iLoop++)
    {
        //printf("this is thread 2: %s\n", g_write);
        WaitForSingleObject(g_hThreadEvent[1], INFINITE);
        strcat(g_write, "B");
        SetEvent(g_hThreadEvent[2]);
    }
    _endthreadex(0);
    return 0;  
} 
//线程3函数   
unsigned int __stdcall ThreadFun3(PVOID pM)  
{  
    int iLoop = 0;
    for (iLoop; iLoop < g_Number; iLoop++)
    {
        //printf("this is thread 2: %s\n", g_write);
        WaitForSingleObject(g_hThreadEvent[2], INFINITE);
        strcat(g_write, "C");
        SetEvent(g_hThreadEvent[0]);
    }
    _endthreadex(0);
    return 0;  
} 
void Init(void)
{
    g_hThreadEvent[0] = CreateEvent(NULL, FALSE, TRUE, NULL);
    g_hThreadEvent[1] = CreateEvent(NULL, FALSE, FALSE, NULL);
    g_hThreadEvent[2] = CreateEvent(NULL, FALSE, FALSE, NULL);
    memset(g_write, NULL, sizeof(g_write));
}
void Release(void)
{
    int iLoop = 0; 
    for (iLoop = 0; iLoop < MAXHANDLE; iLoop++)
    {
        CloseHandle(handle[iLoop]);
    }
}
int main( int Argc, char* Argv[])
{
    int uiNumber = 10;   //需要重复打印的次数
    int *num     = NULL;
    Init();
    num  = (int*)malloc(sizeof(int));
    *num = uiNumber;
    handle[0] = (HANDLE)_beginthreadex(NULL, 0, ThreadFun1, num, 0, NULL);
    handle[1] = (HANDLE)_beginthreadex(NULL, 0, ThreadFun2, NULL, 0, NULL);
    handle[2] = (HANDLE)_beginthreadex(NULL, 0, ThreadFun3, NULL, 0, NULL);
    WaitForMultipleObjects(MAXHANDLE, handle, TRUE, INFINITE);
    Release();
    printf("g_write = %s\n", g_write);
    system("pause");
    return 0;
}