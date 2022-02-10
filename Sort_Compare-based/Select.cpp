// 简单选择、堆（从小到大排序）
#include <iostream>
using namespace std;

#define MAXN 100

int num[MAXN];
int N;

void direct(int num[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        int minPos = i;
        for (int j = i + 1; j < N; j++)
            if (num[j] < num[minPos])
                minPos = j;
        swap(num[i], num[minPos]);
    }
}

int main()
{
    cout << "Please input how many numbers?" << endl;
    cin >> N;
    cout << "Please input the numbers:" << endl;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    direct(num, N);
    for (int i = 0; i < N; i++)
        cout << num[i] << ' ';

    return 0;
}