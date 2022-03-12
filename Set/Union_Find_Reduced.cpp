#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef int ElementType;
typedef int SetName;                  // 用下标表示集合的名称
typedef ElementType SetType[MAXSIZE]; // 这个写法很不好理解

SetName Find(SetType S, ElementType X) // 因为下标就是Data，这里可以把X当做下标用
{
    for (; S[X] >= 0; X = S[X]) // 找出X在哪个集合
        ;
    return X;
}
void Union(SetType S, SetName Root1, SetName Root2)
{
    // 找到两个元素所属的Root1和Root2对应的不同集合后直接合并Root1和Root2
    S[Root2] = Root1;
}