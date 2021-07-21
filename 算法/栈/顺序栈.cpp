#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef struct 
{
    int data[MAXSIZE];
    int top;
}SqStack;

//初始化
void InitStack(SqStack &S)
{
    S.top = -1;
}

//进栈
bool Push(SqStack &S,int x)
{
    if(S.top == MAXSIZE -1)
    {
        return false;
    }
    else
    {
        S.top++;
        S.data[S.top] = x;
        return true;
    }
}

//出栈
bool Pop(SqStack &S,int &e)
{
    if(S.top == -1)
    {
        return false;
    }
    else
    {
        e = S.data[S.top];
        S.top--;
        return true;
    }
}
int main()
{
    SqStack S;
    InitStack(S);
    Push(S,1);
    Push(S,2);
    Push(S,3);
    int e = 0;
    Pop(S,e);
    printf("%d",e);
    return 0;
}
