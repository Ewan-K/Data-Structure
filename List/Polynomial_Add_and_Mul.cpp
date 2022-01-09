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
Poly PolyMul(Poly P1, Poly P2);
void Attach(int coe, int expo, Poly *pRear); // 传rear的地址以避免传rear时无法返回有效结果
int Compare(int e1, int e2);

int main()
{
    int num1, num2;
    int i;
    int coe, expo;
    Poly res1, res2, p;

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

    res1 = PolyAdd(P1F->next, P2F->next);
    p = res1;
    printf("P1、P2和的结果为：\n");
    while (p)
    {
        printf("%d %d\n", p->coe, p->expo);
        p = p->next;
    }
    res2 = PolyMul(P1F->next, P2F->next);
    p = res2;
    printf("P1、P2积的结果为：\n");
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
Poly PolyMul(Poly P1, Poly P2)
{
    Poly t1, t2, P, rear, t;
    int e, c;
    if (!P1 || !P2)
        return NULL;

    t1 = P1;
    t2 = P2;
    P = (Poly)malloc(sizeof(PNode));
    P->next = NULL;
    rear = P;
    while (t2)
    {
        Attach(t1->coe * t2->coe, t1->expo + t2->expo, &rear);
        t2 = t2->next;
    }
    t1 = t1->next;
    while (t1)
    {
        t2 = P2;
        rear = P;
        while (t2)
        {
            e = t1->expo + t2->expo;
            c = t1->coe * t2->coe;
            // 将新的节点按照降序插入链表中
            while (rear->next && rear->next->expo > e)
                rear = rear->next;
            if (rear->next && rear->next->expo == e) // 合并
            {
                if (rear->next->coe + c)
                {
                    rear->next->coe += c;
                }
                else
                {
                    t = rear->next;
                    rear->next = t->next;
                    free(t);
                }
            }
            else // 插入
            {
                t = (Poly)malloc(sizeof(PNode));
                t->coe = c;
                t->expo = e;
                t->next = rear->next;
                rear->next = t;
                rear = rear->next;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    t2 = P;
    P = P->next;
    free(t2);
    return P;
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
