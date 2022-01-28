// BFS求解无权图上的单源最短路问题
#include <iostream>
#define MAXN 100
using namespace std;

int G[MAXN][MAXN], Nv, Ne;

void buildGraph()
{
    int v1, v2, w;
    cin >> Nv; // 输入点的个数
    for (int i = 0; i < Nv; i++)
        for (int j = 0; j < Nv; j++)
            G[i][j] = 0;
    cin >> Ne;
    for (int i = 0; i < Ne; i++)
    {
        cin >> v1 >> v2 >> w;
        G[v1][v2] = w;
        G[v2][v1] = w;
    }
}

void solve()
{
}

int main()
{
    buildGraph();
    for (int i = 0; i < Nv; i++)
    {
        for (int j = 0; j < Nv; j++)
            cout << G[i][j];
        cout << endl;
    }
    solve();
    return 0;
}