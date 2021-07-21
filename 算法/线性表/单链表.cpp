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
    L->next = NULL;//不加的话最后一个结点的next不知道会指到哪去
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

//删除
bool DeleteList(LinkList &L,int i,int e)
{
    if(i < 1)
    {
        return false;
    }
    else
    {
        LNode *p;//p指向被删除结点的前一个结点
        p = L;
        int j = 0;
        while (j < i - 1 && p != NULL)//寻找要删除结点的前一个结点
        {
            p = p->next;
            j++;
        }
        LNode *q;//q指向被删除结点
        q = p->next;
        e = q->data;
        p->next = q->next;
        free(q);
        return true;
    }
}

//按位查找（O(n)）
LNode * getElem(LinkList L, int i)
{
    int j = 0;
    LNode *p = L;
    while(j < i && p != NULL)
    {
        p = p->next;
        j++;
    }
    return p;
}

//按值查找（O(n)）
LNode * LocateElem(LinkList L, int e)
{
    LNode *p = L;
    while(p->data != e && p != NULL)
    {
        p = p->next;
    }
    return p;
}

//求表长（O(n)）
int getLength(LinkList L)
{
    LNode *p = L;
    int len = 0;
    while(p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}
int main()
{
    LinkList L;
    InitList(L);
    //HeadInsert(L);
    TailInsert(L);
    int e = 0;
    DeleteList(L,3,e);
    LNode *p = L->next;
    while(p != NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
    printf("%d",getElem(L,3)->data);
    printf("%d",LocateElem(L,5)->data);
    printf("%d",getLength(L));
}