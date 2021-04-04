#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ERROR -100
typedef struct DNode *Stack;
struct DNode
{
    int Data[MAXSIZE];
    int Top1;
    int Top2;
};

Stack createEmpty();
void Output(Stack S);
void Push(int X, Stack S, int Tag);
int Pop(Stack S, int Tag);

int main()
{
    int num1, num2;
    //建栈
    Stack S = createEmpty();
    //压栈
    Push(1, S, 1);
    Push(2, S, 2);
    //输出
    Output(S);

    printf("\n");

    //出栈
    num1 = Pop(S, 1);
    printf("%d\n", num1);
    num2 = Pop(S, 2);
    printf("%d\n", num2);
    //输出
    Output(S);

    getchar();
}

Stack createEmpty()
{
    Stack S = (Stack)malloc(sizeof(DNode));
    S->Top1 = -1;
    S->Top2 = MAXSIZE;
    return S;
}

void Output(Stack S)
{
    int i;

    if (S->Top1 == -1)
    {
        printf("Stack1 is empty!\n");
    }
    else
    {
        printf("Stack1中的元素为：\n");
        for (i = 0; i <= S->Top1; i++)
            printf("%d ", S->Data[i]);
    }

    if (S->Top2 == MAXSIZE)
    {
        printf("Stack2 is empty!\n");
    }
    else
    {
        printf("\nStack2中的元素为：\n");
        for (i = MAXSIZE - 1; i >= S->Top2; i--)
            printf("%d ", S->Data[i]);
    }
    return;
}

void Push(int X, Stack S, int Tag)
{
    if (S->Top2 - S->Top1 == 1)
    {
        printf("The Stack is full!");
        return;
    }
    if (Tag == 1)
        S->Data[++S->Top1] = X;
    else
        S->Data[--S->Top2] = X;
    return;
}

int Pop(Stack S, int Tag)
{
    if (Tag == 1)
    {
        if (S->Top1 == -1)
        {
            printf("Stack1 is empty!");
            return ERROR;
        }
        else
            return S->Data[S->Top1--];
    }
    else
    {
        if (S->Top2 == MAXSIZE)
        {
            printf("Stack2 is empty!");
            return ERROR;
        }
        else
            return S->Data[S->Top2++];
    }
}