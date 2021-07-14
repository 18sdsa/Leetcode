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

//元素逆置
void InvertList(SqList &L)
{
    int temp;
    for(int i=0; i<L.length/2; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length-1-i];
        L.data[L.length-1-i] = temp;

    }
}
int main()
{
    SqList L;
    InitList(L);
    for(int i = 0; i < L.MaxSize; i++)
    {
        L.data[i] = i;
        L.length++;
    }
    InvertList(L);
        //print sqlist
    for(int i = 0; i < L.length; i++)
    {
        printf("%d",L.data[i]);
        
    }
    return 0;
}