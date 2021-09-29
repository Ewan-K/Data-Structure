#include <stdio.h>
#include <stdlib.h>

#define VertexNumMax 50

typedef int Vertex;
typedef struct GNode *MGraph;
struct GNode
{
    int Nv;
    int Ne;
    int G[VertexNumMax][VertexNumMax];
};
typedef struct ENode *Edge;
struct ENode
{
    Vertex V1, V2;
    // int Weight;
};

MGraph createGraph(int vertexNum);
void insertEdge(MGraph Graph, Edge E);
MGraph buildGraph();

int main()
{
    buildGraph();
    getchar();
}

MGraph createGraph(int vertexNum)
{
    MGraph Graph;
    Vertex V, W;
    Graph = (MGraph)malloc(sizeof(GNode));
    Graph->Nv = vertexNum;
    Graph->Ne = 0;
    for (V = 0; V < Graph->Nv; V++)
        for (W = 0; W < Graph->Nv; W++)
            Graph->G[V][W] = 0;

    return Graph;
}

void insertEdge(MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = 1;
    // 有权图加上权重
    // Graph->G[E->V1][E->V2] = E->Weight;
    // 无向图加另一个方向的边
    Graph->G[E->V2][E->V1] = 1;
}

MGraph buildGraph()
{
    int i, Nv;
    Edge E;
    MGraph Graph;
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
    // 如果点有数据的话还要赋值

    return Graph;
}