// 归并（从小到大排序）
#include <iostream>
using namespace std;

#define MAXN 100

void MergeSort(int num[], int N)
{
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
    MergeSort(num, N);
    for (int i = 0; i < N; i++)
        cout << num[i] << ' ';

    return 0;
}