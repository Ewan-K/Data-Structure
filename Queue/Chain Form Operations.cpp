#include <stdio.h>
#include <stdlib.h>

#define ERROR -100

typedef struct QNode *Queue;
struct Node
{
    int Data;
    Node *Next;
};
struct QNode
{
    Node *front;
    Node *rear;
};

Queue createQ();
void Output(Queue Q);
void Enqueue(int X, Queue Q);
int Dequeue(Queue Q);

int main()
{
    int num1;
    Queue Q = createQ();
    // 进队
    Enqueue(1, Q);
    Enqueue(2, Q);
    Enqueue(3, Q);
    Output(Q);

    printf("\n");

    // 出队
    num1 = Dequeue(Q);
    printf("%d\n", num1);
    Output(Q);

    getchar();
}

Queue createQ()
{
    Queue Q = (Queue)malloc(sizeof(QNode));
    Q->front = Q->rear = NULL;
    return Q;
}
void Output(Queue Q)
{
    Node *PtrQ;
    if (Q->front == NULL)
    {
        printf("The Queue is empty!");
        return;
    }
    PtrQ = Q->front;
    while (PtrQ)
    {
        printf("%d ", PtrQ->Data);
        PtrQ = PtrQ->Next;
    }
    return;
}

void Enqueue(int X, Queue Q)
{
    Node *PtrQ = (Node *)malloc(sizeof(Node));
    PtrQ->Data = X;
    PtrQ->Next = NULL;
    if (Q->front == NULL) // 若队列为空，需要改变front，而如果不为空则只需改变rear
        Q->front = Q->rear = PtrQ;
    else
    {
        Q->rear->Next = PtrQ;
        Q->rear = PtrQ;
    }
    return;
}

int Dequeue(Queue Q)
{
    Node *PtrQ;
    int X;
    if (Q->front == NULL)
    {
        printf("The Queue is empty!");
        return ERROR;
    }
    PtrQ = Q->front;
    if (Q->front == Q->rear) // 若队列仅有一个元素，出队后需要改变rear，而如果有更多元素则不需改变rear
        Q->front = Q->rear = NULL;
    else
        Q->front = Q->front->Next;
    X = PtrQ->Data;
    free(PtrQ);
    return X;
}