#include <stdio.h>
#include <stdlib.h>

enum TYPE
{
    INT,
    DOUBLE,
    CHAR
};

typedef struct Node *List;
struct Node
{
    void *Data;
    enum TYPE type;
    List Next;
};

List createEmpty();                                     // 建立空链表
void Output(List PtrL);                                 // 遍历链表输出
List FindKth(List PtrL, int K);                         // 查找并指向第K个元素
List Insert(List PtrL, int K, enum TYPE type, void *x); // 在第K个位置插入类型为type的元素
List DeleteKth(List PtrL, int K);                       // 删除第K个位置的元素
List Reverse(List PtrL);                                // 逆置链表
List Merge(List PtrL1, List PtrL2);                     // 合并链表
List sortByType(List PtrL);                             // 按值的类型排序（先INT，再DOUBLE，后CHAR）
void Destroy(List PtrL);                                // 销毁链表

int main()
{
    List PtrL1, PtrL2;
    int int1 = 1, int2 = 2;
    double double1 = 2020.11, double2 = 2020.22;
    char ch1 = 'a', ch2 = 'b';
    // 建表
    PtrL1 = createEmpty();
    PtrL2 = createEmpty();
    // 插入
    PtrL1 = Insert(PtrL1, 1, INT, &int1);
    PtrL1 = Insert(PtrL1, 2, INT, &int2);
    PtrL1 = Insert(PtrL1, 1, DOUBLE, &double1);
    PtrL2 = Insert(PtrL2, 1, CHAR, &ch1);
    PtrL2 = Insert(PtrL2, 2, CHAR, &ch2);
    PtrL2 = Insert(PtrL2, 3, DOUBLE, &double2);
    // 输出
    printf("插入后的结果：\n");
    printf("PtrL1中元素：\n");
    Output(PtrL1);
    printf("PtrL2中元素：\n");
    Output(PtrL2);

    printf("\n");

    // //删除
    // PtrL1 = DeleteKth(PtrL1, 2);
    // PtrL2 = DeleteKth(PtrL2, 2);
    // //输出
    // printf("删除后的结果：\n");
    // printf("PtrL1中元素：\n");
    // Output(PtrL1);
    // printf("PtrL2中元素：\n");
    // Output(PtrL2);

    // printf("\n");

    // 逆置
    PtrL1 = Reverse(PtrL1);
    PtrL2 = Reverse(PtrL2);
    // 输出
    printf("逆置后的结果：\n");
    printf("PtrL1中元素：\n");
    Output(PtrL1);
    printf("PtrL2中元素：\n");
    Output(PtrL2);

    printf("\n");

    // 合并
    PtrL1 = Merge(PtrL2, PtrL1);
    // 输出
    printf("合并后的结果：\n");
    printf("PtrL1中元素：\n");
    Output(PtrL1);

    printf("\n");

    // 排序
    PtrL1 = sortByType(PtrL1);
    // 输出
    printf("排序后的结果：\n");
    printf("PtrL1中元素：\n");
    Output(PtrL1);

    printf("\n");

    // 销毁
    Destroy(PtrL1);
    PtrL1 = NULL;
    // 输出
    printf("销毁后的结果：\n");
    printf("PtrL1中元素：\n");
    Output(PtrL1);

    getchar();
}

List createEmpty()
{
    List PtrL = NULL;
    return PtrL;
}

List FindKth(List PtrL, int K)
{
    List L = PtrL;
    int i = 1;
    while (L && i < K)
    {
        L = L->Next;
        i++;
    }
    if (i == K)
        return L;
    else
    {
        printf("K位置无法查找！");
        return NULL;
    }
}

List Insert(List PtrL, int K, enum TYPE type, void *x)
{
    List p, l;
    if (K == 1)
    {
        p = (List)malloc(sizeof(struct Node));
        p->Data = x;
        p->type = type;
        p->Next = PtrL;
        return p;
    }
    l = FindKth(PtrL, K - 1);
    if (l)
    {
        p = (List)malloc(sizeof(struct Node));
        p->Data = x;
        p->type = type;
        p->Next = l->Next;
        l->Next = p;
        return PtrL;
    }
    else
    {
        printf("K位置无法插入！\n");
        return NULL;
    }
}

void Output(List PtrL)
{
    List p = PtrL;
    if (!PtrL)
    {
        printf("链表为空！");
        return;
    }
    else
    {
        while (p)
        {
            if (p->type == INT)
                printf("整型，值为%d\n", *(int *)p->Data);
            else if (p->type == CHAR)
                printf("字符型，值为%c\n", *(char *)p->Data);
            else
                printf("浮点型，值为%.2lf\n", *(double *)p->Data);

            p = p->Next;
        }
        return;
    }
}

List DeleteKth(List PtrL, int K)
{
    List p, l;
    if (K == 1)
    {
        p = PtrL;
        PtrL = PtrL->Next;
        free(p);
        return PtrL;
    }
    l = FindKth(PtrL, K - 1);
    if (l && l->Next)
    {
        p = l->Next;
        l->Next = p->Next;
        free(p);
        return PtrL;
    }
    else
    {
        printf("位置K无法删除！");
        return NULL;
    }
}

List Reverse(List PtrL)
{
    List pPre, pCur, pNext;
    pPre = PtrL;
    pCur = pPre->Next;
    pNext = NULL;
    while (pCur)
    {
        pNext = pCur->Next;
        pCur->Next = pPre;
        pPre = pCur;
        pCur = pNext;
    }
    PtrL->Next = NULL;
    PtrL = pPre;
    return PtrL;
}

List Merge(List PtrL1, List PtrL2)
{
    List L = PtrL1;
    while (L->Next)
        L = L->Next;
    L->Next = PtrL2;
    return PtrL1;
}

List sortByType(List PtrL)
{
    List p = PtrL, pIH, pIE, pDH, pDE, pCH, pCE;
    pIH = pIE = NULL;
    pDH = pDE = NULL;
    pCH = pCE = NULL;
    while (p)
    {
        if (p->type == INT)
        {
            if (!pIH)
            {
                pIH = pIE = p;
            }
            else
            {
                pIE->Next = p;
                pIE = p;
            }
        }
        else if (p->type == DOUBLE)
        {
            if (!pDH)
            {
                pDH = pDE = p;
            }
            else
            {
                pDE->Next = p;
                pDE = p;
            }
        }
        else
        {
            if (!pCH)
            {
                pCH = pCE = p;
            }
            else
            {
                pCE->Next = p;
                pCE = p;
            }
        }
        p = p->Next;
    }
    pIE->Next = pDH;
    pDE->Next = pCH;
    pCE->Next = NULL;
    PtrL = pIH;
    return PtrL;
}

void Destroy(List PtrL)
{
    List p;
    while (PtrL)
    {
        p = PtrL;
        PtrL = PtrL->Next;
        free(p);
    }
    return;
}