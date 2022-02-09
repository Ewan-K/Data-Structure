// 归并（从小到大排序）
#include <iostream>
using namespace std;

#define MAXN 100

int num[MAXN];
int N;

void bubble(int num[], int N)
{
}

int main()
{
    cout << "Please input how many numbers?" << endl;
    cin >> N;
    cout << "Please input the numbers:" << endl;
    for (int i = 0; i < N; i++)
        cin >> num[i];

    for (int i = 0; i < N; i++)
        cout << num[i] << ' ';

    return 0;
}