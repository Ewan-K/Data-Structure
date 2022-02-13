// 直接插入、希尔（从小到大排序）
#include <iostream>
using namespace std;

#define MAXN 100

void direct(int num[], int N) // 每次只操作相邻两个元素
{
    for (int P = 1; P < N; P++)
    {
        int tmp = num[P];
        int i = 0;
        for (i = P; i > 0 && tmp < num[i - 1]; i--)
            num[i] = num[i - 1];
        num[i] = tmp;
    }
}

void shell(int num[], int N)
{
    for (int D = N / 2; D > 0; D /= 2)
    {
        for (int P = D; P < N; P++)
        {
            int tmp = num[P];
            int i = 0;
            for (i = P; i > 0 && tmp < num[i - D]; i -= D)
                num[i] = num[i - D];
            num[i] = tmp;
        }
    }
}

int main()
{
    int num[MAXN];
    int N;
    cout << "Please input how many numbers?" << endl;
    cin >> N;
    cout << "Please input the numbers:" << endl;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    // direct(num, N);
    shell(num, N);
    for (int i = 0; i < N; i++)
        cout << num[i] << ' ';

    return 0;
}