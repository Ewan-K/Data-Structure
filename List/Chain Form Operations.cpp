#include <stdio.h>
#include <stdlib.h>

typedef struct LNode *List;
struct LNode
{
    int Data;
    List Next;
};

int Length(List PtrL);
List FindKth(List PtrL, int K);
List Find(List PtrL, int X);
List Insert(int X, List PtrL, int K); // 由于没有加入头结点，所以如果删除了第一个节点需要返回一个新的头指针
List Delete(List PtrL, int K);

int main()
{
    List PtrL = NULL;
    List L;
    PtrL = Insert(1, PtrL, 1);
    PtrL = Insert(2, PtrL, 2);
    PtrL = Insert(3, PtrL, 2);
    PtrL = Insert(4, PtrL, 1);
    printf("%d\n", Length(PtrL));
    PtrL = Delete(PtrL, 2);
    printf("%d\n", Length(PtrL));
    if (Find(PtrL, 5))
        printf("Found it!\n");
    else
        printf("Not Found!\n");
    L = PtrL;
    while (L)
    {
        printf("%d ", L->Data);
        L = L->Next;
    }
    getchar();
}

int Length(List PtrL)
{
    List n = PtrL; // PtrL指向表的第一个节点
    int i = 0;
    while (n)
    {
        n = n->Next;
        i++;
    }
    return i;
}
List FindKth(List PtrL, int K)
{
    if (K < 1 || K > Length(PtrL))
    {
        printf("Position K is illegal!\n");
        return NULL;
    }
    List n = PtrL;
    int i = 1;
    while (i < K)
    {
        n = n->Next;
        i++;
    }
    return n;

    // while (n && i < K)
    // {
    //     n = n->Next;
    //     i++;
    // }
    // if (i == K)
    // return n;
    // else
    // return NULL;
}
List Find(List PtrL, int X)
{
    List n = PtrL;
    while (n && n->Data != X)
        n = n->Next;
    return n;
}
List Insert(int X, List PtrL, int K) // 在第K-1个节点之后插入
{
    List p, n;
    if (K == 1)
    {
        n = (List)malloc(sizeof(LNode));
        n->Data = X;
        n->Next = PtrL;
        return n;
    }
    p = FindKth(PtrL, K - 1);
    if (!p)
    {
        printf("Position K is illegal!\n");
        return NULL;
    }
    else
    {
        n = (List)malloc(sizeof(LNode));
        n->Data = X;
        n->Next = p->Next;
        p->Next = n;
        return PtrL;
    }
}
List Delete(List PtrL, int K)
{
    List n, p;
    if (K == 1)
    {
        if (PtrL)
        {
            n = PtrL;
            PtrL = PtrL->Next;
            free(n);
        }
        return PtrL; // else意味着PtrL为空，也可以返回PtrL
    }
    p = FindKth(PtrL, K - 1);
    if (!p)
    {
        printf("Positionn K-1 is illegal!\n");
        return NULL;
    }
    else if (p->Next == NULL)
    {
        printf("Position K is illegal!\n");
        return NULL;
    }
    else
    {
        n = p->Next;
        p->Next = n->Next;
        free(n);
        return PtrL;
    }
}