// 冒泡、快排（从小到大排序）
#include <iostream>
using namespace std;

#define MAXN 100

int num[MAXN];
int N;

void bubble(int num[], int N) // 最大的优势是可以用于链表排序，同样每次只操作相邻两个元素
{
    for (int i = N - 1; i > 0; i--)
    {
        int flag = 0; // 如果中间某趟已经排好序了就不用继续
        for (int j = 0; j < i; j++)
        {
            if (num[j] > num[j + 1])
            {
                flag = 1;
                swap(num[j], num[j + 1]);
            }
        }
        if (flag == 0)
            break;
    }
}

int main()
{
    cout << "Please input how many numbers?" << endl;
    cin >> N;
    cout << "Please input the numbers:" << endl;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    bubble(num, N);
    for (int i = 0; i < N; i++)
        cout << num[i] << ' ';

    return 0;
}