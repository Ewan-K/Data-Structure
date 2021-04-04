#include <stdio.h>
#include <stdlib.h> //not used
//Compare sum of all subsequence

int origf(int N, int A[]);
int betterf(int N, int A[]);

int main()
{
	int N;
	int i;
	int MaxSum;
	int sw;

	scanf("%d", &N);
	int A[N];
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
	printf("请选择使用哪种算法？1 original，2 better");
	scanf("%d", &sw);

	switch (sw)
	{
	case 1:
		MaxSum = origf(N, A);
	case 2:
		MaxSum = betterf(N, A);
	}
	printf("%d", MaxSum);
}

int origf(int N, int A[])
{
	int ThisSum, MaxSum = 0;
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		for (j = i; j < N; j++)
		{
			ThisSum = 0;
			for (k = i; k <= j; k++)
			{
				ThisSum += A[k];
			}
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

int betterf(int N, int A[])
{
	int ThisSum, MaxSum = 0;
	int i, j;
	for (i = 0; i < N; i++)
	{
		ThisSum = 0;
		for (j = i; j < N; j++)
		{
			ThisSum += A[j];
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}
