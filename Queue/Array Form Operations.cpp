#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -100

typedef struct QNode *Queue;
struct QNode
{
    int Data[MAXSIZE];
    int front;
    int rear;
};

Queue createQueue();
void Output(Queue Q);
void Enqueue(int X, Queue Q);
int Dequeue(Queue Q);

int main()
{
    Queue Q = createQueue();
    Enqueue(1, Q);
    Enqueue(2, Q);
    Enqueue(3, Q);
    Enqueue(4, Q);
    Output(Q);

    printf("\n");

    Dequeue(Q);
    Dequeue(Q);
    Dequeue(Q);
    Output(Q);

    printf("\n");

    Enqueue(1, Q);
    Enqueue(2, Q);
    Output(Q);

    getchar();
    return 0;
}

Queue createQueue()
{
    Queue Q = (Queue)malloc(sizeof(QNode));
    Q->front = Q->rear = 0;
    return Q;
}

void Output(Queue Q)
{
    int i;
    if (Q->front == Q->rear)
    {
        printf("The Queue is empty!\n");
        return;
    }
    for (i = (Q->front + 1) % MAXSIZE; i != Q->rear; i = (i + 1) % MAXSIZE)
        printf("%d ", Q->Data[i]);
    printf("%d\n", Q->Data[i]);
    return;
}

void Enqueue(int X, Queue Q)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        printf("The Queue is full!\n");
        return;
    }
    Q->rear = (Q->rear + 1) % MAXSIZE;
    Q->Data[Q->rear] = X;
    return;
}

int Dequeue(Queue Q)
{
    if (Q->front == Q->rear)
    {
        printf("The Queue is empty!\n");
        return ERROR;
    }
    Q->front = (Q->front + 1) % MAXSIZE;
    return Q->Data[Q->front];
}