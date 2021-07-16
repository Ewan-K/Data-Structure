#include <stdio.h>
#include <stdlib.h>

#define ERROR -100

typedef struct SNode *Stack;
struct SNode
{
    int Data;
    Stack Next;
};
Stack createStack();
int isEmpty(Stack);
void Output(Stack);
void Push(int X, Stack S);
int Pop(Stack);

int main()
{
    int num1, num2;
    // 建栈
    Stack S = createStack();
    // 压栈
    Push(1, S);
    Push(2, S);
    // 输出
    Output(S);

    printf("\n");

    // 出栈
    num1 = Pop(S);
    printf("%d\n", num1);
    num2 = Pop(S);
    printf("%d\n", num2);
    // 输出
    Output(S);

    getchar();
}

Stack createStack()
{
    Stack S = (Stack)malloc(sizeof(SNode));
    S->Next = NULL;
    return S;
}

int isEmpty(Stack S)
{
    return (S->Next == NULL);
}

void Output(Stack S)
{
    Stack PtrS = S->Next;
    if (isEmpty(S))
    {
        printf("The Stack is empty!");
        return;
    }
    while (PtrS)
    {
        printf("%d ", PtrS->Data);
        PtrS = PtrS->Next;
    }
    return;
}

void Push(int X, Stack S)
{
    Stack PtrS = (Stack)malloc(sizeof(SNode));
    PtrS->Data = X;
    PtrS->Next = S->Next;
    S->Next = PtrS;
}

int Pop(Stack S)
{
    Stack PtrS;
    int X;
    if (isEmpty(S))
    {
        printf("The Stack is empty!");
        return ERROR;
    }
    PtrS = S->Next;
    X = PtrS->Data;
    S->Next = PtrS->Next;
    free(PtrS);
    return X;
}