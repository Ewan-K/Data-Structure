// BFS求解无权图上的单源最短路问题
#include <queue>
#include <iostream>

#define MAXN 100
using namespace std;

int G[MAXN][MAXN], Nv, Ne;
int dist[MAXN], path[MAXN];

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
        cin >> v1 >> v2;
        G[v1][v2] = 1;
        G[v2][v1] = 1;
    }
}

void solve(int s)
{
    queue<int> Q;
    Q.push(s);
    // 初始化dist和path数组
    for (int i = 0; i < Nv; i++)
        dist[i] = path[i] = -1;
    // 入栈source node
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        queue<int> Q_temp;
        for (int i = 0; G[v][i] != 0 && i != s; i++)
            Q_temp.push(i);
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
    for (int i = 0; i < Nv; i++)
    {
        for (int j = 0; j < Nv; j++)
            cout << G[i][j];
        cout << endl;
    }
    cout << "Please input the index of the source node: " << endl;
    cin >> s;
    solve(s);
    cout << "Please input the index of the target node: " << endl;
    cin >> t;
    cout << "The cost of the shortest path between them is: " << dist[t] << endl;
    cout << "The path are(need to be reversed): " << endl;
    int k = t;
    while (k != s)
    {
        cout << k << ' ';
        k = path[k];
    }

    return 0;
}