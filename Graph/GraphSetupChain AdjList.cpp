#include <stdio.h>
#include <stdlib.h>

#define VertexNumMax 50

typedef int Vertex;
typedef struct GNode *LGraph;
struct GNode
{
    int Nv;
    int Ne;
    AdjList G;
};
typedef struct arrayNode
{
    PtrToAdjLNode FirstEdge;
    //int Data;
} AdjList[VertexNumMax];
typedef struct AdjLNode *PtrToAdjLNode;
struct AdjLNode
{
    Vertex Index;
    PtrToAdjLNode Next;
    //int Weight;
};
typedef struct ENode *Edge;
struct ENode
{
    int V1, V2;
    //int Weight;
};

LGraph createGraph(int vertexNum);
void insertEdge(LGraph Graph, Edge E);
LGraph buildGraph();

int main()
{
    buildGraph();
    getchar();
}

LGraph createGraph(int vertexNum)
{
    LGraph Graph;
    Vertex V;
    Graph = (LGraph)malloc(sizeof(GNode));
    Graph->Nv = vertexNum;
    Graph->Ne = 0;
    for (V = 0; V < Graph->Nv; V++)
        Graph->G[V].FirstEdge = NULL;
    return Graph;
}

void insertEdge(LGraph Graph, Edge E)
{
    PtrToAdjLNode newNode;
    newNode = (PtrToAdjLNode)malloc(sizeof(AdjLNode));
    newNode->Index = E->V2;
    newNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = newNode;

    //无向图还要插入<V2, V1>
    newNode = (PtrToAdjLNode)malloc(sizeof(AdjLNode));
    newNode->Index = E->V1;
    newNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = newNode;
}

LGraph buildGraph()
{
    int Nv, i;
    Edge E;
    LGraph Graph;
    printf("请输入点的数量：\n");
    scanf("%d", &Nv);
    Graph = createGraph(Nv);
    printf("请输入边的数量：\n");
    scanf("%d", &(Graph->Ne));
    if (Graph->Ne)
    {
        E = (Edge)malloc(sizeof(ENode));
        for (i = 0; i < Graph->Ne; i++)
        {
            scanf("%d", &E->V1);
            scanf("%d", &E->V2);
            insertEdge(Graph, E);
        }
    }
    //如果点有数据的话还要赋值

    return Graph;
}
