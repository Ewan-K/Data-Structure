// 简单选择、堆（从小到大排序），参考Tree/Heap.cpp
#include <iostream>
using namespace std;

#define MAXN 100

void direct(int num[], int N) // 可以交换不相邻的两个元素，但是受到ScanForMin部分的制约，所以堆排序就此改进
{
    for (int i = 0; i < N - 1; i++)
    {
        int minPos = i;
        // ScanForMin
        for (int j = i + 1; j < N; j++)
            if (num[j] < num[minPos])
                minPos = j;
        swap(num[i], num[minPos]);
    }
}

// void Create()
// {
//     ::size = 0; // 当前最后一个元素的下标
//     H[0] = MINH; // 排序里不需要哨兵，下标从0开始
// }
// 已经有了一个数组，不需要通过插入来建堆
// void Insert(int X)
// {
//     int i;
//     for (i = ++::size; num[i / 2] > X; i /= 2)
//         num[i] = num[i / 2];
//     num[i] = X;
// }

void percDown(int num[], int N) // Adjust成一个最大堆
{
    if (N == 0)
        return;
    for (int i = (N - 1 - 1) / 2; i >= 0; i--) // 注意N是个数，不是下标，又因为没有哨兵，所以父节点不是N/2
    {
        int parent, child;
        for (parent = i; parent * 2 + 1 < N; parent = child)
        {
            child = parent * 2 + 1;
            if (child + 1 < N && num[child] < num[child + 1])
                child++;
            if (num[parent] < num[child])
                swap(num[parent], num[child]);
            else
                break;
        }
    }
}

void Heap(int num[], int N) // 建一个最大堆，不断将最大的元素放到数组最后，实现从小到大排序，这样节省了空间
{
    percDown(num, N);
    for (int i = N - 1; i > 0; i--)
    {
        // for (int j = 0; j < N; j++)
        //     cout << num[j] << ' ';
        // cout << endl;
        swap(num[0], num[i]);
        // for (int j = 0; j < N; j++)
        //     cout << num[j] << ' ';
        // cout << endl;
        percDown(num, i);
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
    Heap(num, N);
    for (int i = 0; i < N; i++)
        cout << num[i] << ' ';

    return 0;
}