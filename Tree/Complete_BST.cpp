// 将输入的数组放到一个完全二叉搜索树中
#include <iostream>
#include <cmath>
#define MAXN 100
using namespace std;

void solve(int Left, int Right, int TRoot); // 从A的Left到Right中选出一个根节点放到TRoot
int getLeftLength(int n);                   // 计算n个节点的完全二叉树的左子树中有多少个节点
int num[MAXN];                              // input
int T[MAXN];                                // solution

int main()
{
    int N;
    cout << "Please input how many numbers:" << endl;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];

    solve(0, N - 1, 0); // 最开始TRoot为T中第一个元素，下标为0
    for (int i = 0; i < N; i++)
        cout << T[i] << endl;

    return 0;
}

void solve(int Left, int Right, int TRoot)
{
    int n;
    int L;
    int leftTRoot;
    int rightTRoot;
    n = Right - Left + 1;
    if (n == 0)
        return;
    L = getLeftLength(n);
    T[TRoot] = num[Left + L];
    leftTRoot = TRoot * 2 + 1;
    rightTRoot = leftTRoot + 1;
    solve(Left, Left + L - 1, leftTRoot);
    solve(Left + L + 1, Right, rightTRoot);
}

int getLeftLength(int n)
{
    int H = floor(log(n + 1));
    int X = n + 1 - pow(2, H);
    if (X < pow(2, H - 1))
        ;
    else
        X = pow(2, H - 1);
    return pow(2, H - 1) - 1 + X;
}