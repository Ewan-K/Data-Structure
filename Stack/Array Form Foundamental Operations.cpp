#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ERROR -100

typedef struct SNode *Stack;
struct SNode
{
    int Data[MAXSIZE];
    int Top;
};

Stack createStack(void);
void Push(int X, Stack PtrS);
void Output(Stack PtrS);
int Pop(Stack PtrS);

int main()
{
    int test;
    //建立堆栈
    Stack S = createStack();
    //压栈
    Push(1, S);
    Push(2, S);
    //输出
    Output(S);

    printf("\n");

    //出栈
    test = Pop(S);
    printf("test = %d\n", test);
    //输出
    Output(S);
    getchar();
    return 0;
}

Stack createStack(void)
{
    Stack S = (Stack)malloc(sizeof(SNode));
    S->Top = -1;
    return S;
}

void Output(Stack PtrS)
{
    int i;
    for (i = 0; i <= PtrS->Top; i++)
        printf("%d ", PtrS->Data[i]);
    printf("\n");
}

void Push(int X, Stack PtrS)
{
    if (PtrS->Top == MAXSIZE - 1)
    {
        printf("Stack is full!");
        return;
    }
    PtrS->Data[++PtrS->Top] = X;
    return;
}

int Pop(Stack PtrS)
{
    if (PtrS->Top == -1)
    {
        printf("Stack is empty!");
        return ERROR;
    }
    return PtrS->Data[PtrS->Top--];
}