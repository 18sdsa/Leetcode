#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *LinkList;

bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));//头结点
    if(L == NULL)//内存不足
    {
        return false;
    }
    else
    {
        L->next = NULL;
        return true;
    }
}

//插入
bool InsertList(LinkList &L, int i, int e)
{
    if(i < 1)
    {
        return false;
    }
    else
    {
        LNode *p;//p指向当前扫描到的节点
        int j = 0;
        p = L;
        while(p != NULL && j < i-1)//找到要插入位置的前一个节点
        {
            p = p->next;
            j++;
        }
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}

int main()
{
    LinkList L;
    InitList(L);
    InsertList(L,1,1);
    InsertList(L,2,2);
    InsertList(L,3,3);
    InsertList(L,4,4);
    InsertList(L,5,5);
    InsertList(L,6,6);
    LNode *p = L;
    while(p->next != NULL)
    {
        printf("%d\n",p->data);
    }
}