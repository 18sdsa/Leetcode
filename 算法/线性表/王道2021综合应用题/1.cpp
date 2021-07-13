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
        L.data[i-1] = L.data[L.length-1];
        L.length--;
        return true;
    }
}

//查找最小值
int MinElem(SqList L)
{
    int min = L.data[0];//最小值
    int index = 0;//最小值的位序
    for(int i = 0; i < L.length; i++)
    {
        if(min > L.data[i])
        {
            min = L.data[i];
            index = i+1;
        }
    }
    return index;
}
int main()
{
    SqList L;
    InitList(L);
    ListInsert(L,1,4);
    ListInsert(L,2,11);
    ListInsert(L,3,3);
    ListInsert(L,4,6);
    ListInsert(L,5,2);
    ListInsert(L,6,6);
    ListInsert(L,7,7);
    printf("最小值%d的位序为%d",L.data[MinElem(L)-1],MinElem(L));
    printf("\n");
    int e = -1;
    if(ListDelete(L,MinElem(L),e))
    {
        printf("%d""删除成功",e);
    }
    else
    {
        printf("删除失败");
    } 
    printf("\n");
    //print sqlist
    for(int i = 0; i < L.length; i++)
    {
        printf("%d ",L.data[i]);
        
    }
    return 0;
}