#include <stdio.h>
#define MAXSIZE 10

typedef struct
{
    int data[MAXSIZE];//定义静态数组
    int length;

}SqList;

//初始化
void InitList(SqList &L)
{
    L.length = 0;
}

int main()
{
    SqList L;
    InitList(L);
    for(int i = 0; i < L.length; i++)
    {
        printf("%d\n",L.data[i]);
        
    }
}