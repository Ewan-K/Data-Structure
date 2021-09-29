#include <stdio.h>
#include <stdlib.h>

// 多项式加法可以采用结构数组（存储系数和指数）也可以采用链表，显然链表更便于维护顺序

typedef struct PNode *Poly;
struct PNode
{
    int coe;
    int expo;
    Poly next;
};
Poly P1 = (Poly)malloc(sizeof(PNode)), P2 = (Poly)malloc(sizeof(PNode));
Poly P1F = P1; // 由于采用Attach函数插入新节点，所以链表有头结点
Poly P2F = P2;

Poly PolyAdd(Poly P1, Poly P2);
void Attach(int coe, int expo, Poly *pRear); // 传rear的地址以避免传rear时无法返回有效结果
int Compare(int e1, int e2);

int main()
{
    int num1, num2;
    int i;
    int coe, expo;
    Poly res, p;

    printf("请输入P1的项数：");
    scanf("%d", &num1);
    printf("请输入P2的项数：");
    scanf("%d", &num2);
    printf("请输入P1所有项的值\n：");
    for (i = 0; i < num1; i++)
    {
        scanf("%d", &coe);
        scanf("%d", &expo);
        Attach(coe, expo, &P1);
    }
    printf("请输入P2所有项的值\n：");
    for (i = 0; i < num2; i++)
    {
        scanf("%d", &coe);
        scanf("%d", &expo);
        Attach(coe, expo, &P2);
    }

    res = PolyAdd(P1F->next, P2F->next);
    p = res;
    printf("P1、P2和的结果为：\n");
    while (p)
    {
        printf("%d %d\n", p->coe, p->expo);
        p = p->next;
    }
    getchar();
    getchar();
}

Poly PolyAdd(Poly P1, Poly P2)
{
    Poly front, rear, temp;
    int sum;
    rear = (Poly)malloc(sizeof(PNode));
    front = rear;
    while (P1 && P2)
    {
        switch (Compare(P1->expo, P2->expo))
        {
        case 1:
            Attach(P1->coe, P1->expo, &rear);
            P1 = P1->next;
            break;
        case -1:
            Attach(P2->coe, P2->expo, &rear);
            P2 = P2->next;
            break;
        case 0:
            sum = P1->coe + P2->coe;
            if (sum)
                Attach(sum, P1->expo, &rear);
            P1 = P1->next;
            P2 = P2->next;
            break;
        }
    }
    for (; P1; P1 = P1->next)
        Attach(P1->coe, P1->expo, &rear);
    for (; P2; P2 = P2->next)
        Attach(P2->coe, P2->expo, &rear);
    // rear->next = NULL;
    temp = front;
    front = front->next;
    free(temp);
    return front;
}
void Attach(int c, int e, Poly *pRear)
{
    Poly P;
    P = (Poly)malloc(sizeof(PNode));
    P->coe = c;
    P->expo = e;
    P->next = NULL;
    (*pRear)->next = P;
    *pRear = P;
    return;
}
int Compare(int e1, int e2)
{
    if (e1 > e2)
        return 1;
    else if (e1 < e2)
        return -1;
    else
        return 0;
}
