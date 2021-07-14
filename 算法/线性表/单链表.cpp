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

//头插法
LinkList HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    scanf("%d",&x);
    while(x != 999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}

//尾插
LinkList TailInsert(LinkList &L)
{
    LNode *s = L;
    LNode *r = L;
    int x;
    scanf("%d",&x);
    while(x != 999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;//尾指针后移
        scanf("%d",&x);
    }
    r->next = NULL;
    return L;
}
int main()
{
    LinkList L;
    InitList(L);
    //HeadInsert(L);
    TailInsert(L);
    LNode *p = L;
    while(p != NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}