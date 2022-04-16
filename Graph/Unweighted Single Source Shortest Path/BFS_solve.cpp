// BFS求解无权图上的单源最短路问题（本例为有向无权图）
/*
7
12
0 1
0 3
1 3
1 4
2 0
2 5
3 2
3 4
3 5
3 6
4 6
6 5
*/
#include <queue>
#include <iostream>

#define MAXN 100
using namespace std;

int G[MAXN][MAXN], Nv, Ne;
int dist[MAXN], path[MAXN];

void buildGraph()
{
    int v1, v2;
    cin >> Nv; // 输入点的个数
    for (int i = 0; i < Nv; i++)
        for (int j = 0; j < Nv; j++)
            G[i][j] = 0;
    cin >> Ne; // 输入边的个数
    for (int i = 0; i < Ne; i++)
    {
        cin >> v1 >> v2;
        G[v1][v2] = 1;
    }
}

void solve(int s)
{
    queue<int> Q;
    // 入栈source node
    Q.push(s);
    // 初始化dist和path数组
    for (int i = 0; i < Nv; i++)
        dist[i] = path[i] = -1;
    dist[s] = 0;
    while (!Q.empty())
    {
        queue<int> Q_temp;
        int v = Q.front();
        Q.pop();
        for (int i = 0; i < Nv; i++)
            if (G[v][i] == 1)
                Q_temp.push(i); // 其中可能有重复的i

        while (!Q_temp.empty())
        {
            int adj = Q_temp.front();
            Q_temp.pop();
            if (dist[adj] == -1)
            {
                dist[adj] = dist[v] + 1;
                path[adj] = v;
                Q.push(adj);
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