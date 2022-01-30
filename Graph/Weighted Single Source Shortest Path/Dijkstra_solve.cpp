// Dijkstra求解带权图上的单源最短路问题（本例为有向）
/*
7
12
0 1 2
0 3 1
1 3 3
1 4 10
2 0 4
2 5 5
3 2 2
3 4 2
3 5 8
3 6 4
4 6 6
6 5 1
*/
#include <queue>
#include <iostream>

#define MAXN 100
using namespace std;

int G[MAXN][MAXN], Nv, Ne;
int dist[MAXN], path[MAXN], collected[MAXN];

void buildGraph()
{
    int v1, v2, w;
    cin >> Nv; // 输入点的个数
    for (int i = 0; i < Nv; i++)
        for (int j = 0; j < Nv; j++)
            G[i][j] = 0;
    cin >> Ne; // 输入边的个数
    for (int i = 0; i < Ne; i++)
    {
        cin >> v1 >> v2 >> w;
        G[v1][v2] = w;
    }
}

void solve(int s)
{
    // 初始化dist和path数组
    for (int i = 0; i < Nv; i++)
    {
        path[i] = -1;
        dist[i] = MAXN;
        collected[i] = 0;
    }
    dist[s] = 0;
    while (1)
    {
        int min_dist = MAXN;
        int V = -1;
        // 未收录顶点中dist最小的
        for (int i = 0; i < Nv; i++)
        {
            if (dist[i] < min_dist && collected[i] == 0)
            {
                min_dist = dist[i];
                V = i;
            }
        }
        if (V == -1)
            break;
        collected[V] = 1;
        queue<int> Q_temp;
        for (int i = 0; i < Nv; i++)
            if (G[V][i] != 0 && collected[i] == 0)
                Q_temp.push(i);
        while (!Q_temp.empty())
        {
            int adj = Q_temp.front();
            Q_temp.pop();
            if (dist[V] + G[V][adj] < dist[adj])
            {
                dist[adj] = dist[V] + G[V][adj];
                path[adj] = V;
            }
        }
    }
}

int main()
{
    int s, t;
    buildGraph();
    // for (int i = 0; i < Nv; i++)
    // {
    //     for (int j = 0; j < Nv; j++)
    //         cout << G[i][j];
    //     cout << endl;
    // }
    cout << "Please input the index of the source node: " << endl;
    cin >> s;
    solve(s);
    cout << "Please input the index of the target node: " << endl;
    cin >> t;
    cout << "The cost of the shortest path between them is: " << dist[t] << endl;
    cout << "The path are(from target to source): " << endl;
    for (int i = 0; i < Nv; i++)
        cout << dist[i] << ' ';
    cout << endl;
    for (int i = 0; i < Nv; i++)
        cout << path[i] << ' ';
    cout << endl;
    int k = t;
    while (k != s)
    {
        cout << k << ' ';
        k = path[k];
    }
    cout << k;
    return 0;
}