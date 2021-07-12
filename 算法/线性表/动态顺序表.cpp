#include <stdio.h>
#include <stdlib.h>
#define InitSize 10

typedef struct
{
    int *data;
    int MaxSize;
    int length;
}SqList;

//初始化
void InitList(SqList &L)
{
    L.data = (int *)malloc(InitSize*sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;  
}

//增加动态数组的长度
void IncreaseSize(SqList &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize+len)*sizeof(int));
    for(int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}

int main()
{
    SqList L;
    InitList(L);
    for(int i = 0; i < L.MaxSize; i++)
    {
        L.data[i] = i;
        
    }
    
    for(int i = 0; i < L.MaxSize; i++)
    {
        printf("%d",L.data[i]);
        
    }
}