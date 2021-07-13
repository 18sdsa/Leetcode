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
    for(int i = 0; i < L.MaxSize; i++)//复制原来顺序表中的数据
    {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}

//插入
bool ListInsert(SqList &L, int i, int e)//把e放在第i个位置
{
    if(i > L.length + 1 || i < 1)
    {
        return false;
    }
    else
    {
        for(int j = L.length; j >= i; j--)
        {
            L.data[j] = L.data[j-1];
        }
        L.data[i-1] = e;
        L.length++;
        return true;
    }
}

//删除
bool ListDelete(SqList &L, int i, int &e)
{
    if(i < 1 || i > L.length)
    {
        return false;
    }
    else
    {
        e = L.data[i-1];
        for(int j = i; j < L.length; j++)
        {
            L.data[j-1] = L.data[j];
        }
        L.length--;
        return true;
    }
}

//按值查找
int LocateElem(SqList L, int e)
{
    for(int i = 0; i < L.length; i++)
    {
        if(L.data[i] == e)
        {
            return i+1;
        }
    }
    return -1;
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
    IncreaseSize(L,5);

    printf("%d",L.length);
    printf("\n");
    //test insert
    if(ListInsert(L,11,1))
    {
        printf("插入成功");
    }
    else
    {
        printf("插入失败");
    }
    printf("\n");
    //test delete
    int e = -1;
    if(ListDelete(L,3,e))
    {
        printf("%d""删除成功",e);
    }
    else
    {
        printf("删除失败");
    }
    printf("\n");
    //test locate
    if(LocateElem(L,6))
    {
        printf("该数据在第""%d""个位置",LocateElem(L,6));
    }
    else
    {
        printf("没找到");
    }
    printf("\n");
    //print sqlist
    for(int i = 0; i < L.length; i++)
    {
        printf("%d",L.data[i]);
        
    }
    return 0;
}