#include <iostream>
using namespace std;

#define MAXSIZE 100
// 用一个SetType数组表示所有元素
typedef int ElementType;
typedef struct
{
    ElementType Data; // 如果能把所有数据映射到0~N-1，则可以直接用下标代表Data，不用开辟Data域，见Reduced
    int Parent;
} SetType;

int Find(SetType S[], ElementType X)
{
    int i;
    for (i = 0; i < MAXSIZE && S[i].Data != X; i++) // 找出X在不在集合中
        ;
    if (i > MAXSIZE)
        return -1;
    for (; S[i].Parent >= 0; i = S[i].Parent) // 找出X在哪个集合
        ;
    return i;
}

void Union(SetType S[], ElementType X1, ElementType X2)
{
    int Root1 = Find(S, X1);
    int Root2 = Find(S, X2);
    if (Root1 != Root2)
        S[Root2].Parent = Root1;
}