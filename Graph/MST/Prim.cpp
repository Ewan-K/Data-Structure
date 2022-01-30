#include <queue>
#include <iostream>

#define MAXN 100
using namespace std;

int G[MAXN][MAXN], Nv, Ne;
int dist[MAXN], parent[MAXN], collected[MAXN];
int MST[MAXN];

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
    // 初始化dist和parent数组
    for (int i = 0; i < Nv; i++)
    {
        parent[i] = -2;
        dist[i] = MAXN;
    }
    dist[s] = 0;
    parent[s] = -1; // 表示s为根节点
    while (1)
    {
        int min_dist = MAXN;
        int V = -1;
        // 未收录顶点中dist最小的
        for (int i = 0; i < Nv; i++)
        {
            if (dist[i] < min_dist && dist[i] != 0)
            {
                min_dist = dist[i];
                V = i;
            }
        }
        if (V == -1)
            break;
        dist[V] = 0; // 将点收录进MST中
        queue<int> Q_temp;
        for (int i = 0; i < Nv; i++)
            if (G[V][i] != 0 && dist[i] != 0)
                Q_temp.push(i);
        while (!Q_temp.empty())
        {
            int adj = Q_temp.front();
            Q_temp.pop();
            if (G[V][adj] < dist[adj])
            {
                dist[adj] = G[V][adj];
                parent[adj] = V;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < Nv; i++)
        if (dist[i] == 0)
            cnt++;
    if (cnt != Nv)
        cout << "MST doesn't exist!" << endl;
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
    cout << "The cost of the shortest parent between them is: " << dist[t] << endl;
    cout << "The parent are(from target to source): " << endl;
    for (int i = 0; i < Nv; i++)
        cout << dist[i] << ' ';
    cout << endl;
    for (int i = 0; i < Nv; i++)
        cout << parent[i] << ' ';

    return 0;
}