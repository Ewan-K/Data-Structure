// 将一系列给定数字插入到一个初始为空的小顶堆H。随后对任意给定的下标i，打印从H[i]到根节点的路劲
#include <stdio.h>

#define MAXN 1001
#define MINH -10001

int H[MAXN], size;

void Create()
{
    size = 0;
    H[0] = MINH;
}

void Insert(int X)
{
    int i;
    for (i = ++size; H[i/2] > X; i/=2)
        H[i] = H[i/2];
    H[i] = X;
}

int main()
{
    int n, m, x, i, j;
    scanf("%d %d", &n, &m); // 插入多少个数，查询多少个数
    Create();
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        Insert(x);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &j);
        printf("%d ", H[j]);
        while(j > 1)
        {
            j /= 2;
            printf("%d ", H[j]);
        }
        printf("\n");
    }
    return 0;
}