// 配合第四讲 树（中）习题选讲的动画理解
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode *List;
struct LNode
{
    int Data;
    List Next;
};

List Reverse(List head, int K)
{
    int cnt = 1;
    List Tmp;
    List New = head->Next;
    List Old = New->Next;
    while (cnt < K)
    {
        Tmp = Old->Next;
        Old->Next = New;
        New = Old;
        Old = Tmp;
        cnt++;
    }
    head->Next->Next = Old;
    return New;
}