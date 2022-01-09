#include <stdio.h>
// Compare sum of all subsequence

int origF(int N, int A[]);
int betterF(int N, int A[]);

int main()
{
	int N;
	int i;
	int MaxSum;
	int sw;
	printf("How many numbers?\n");
	scanf("%d", &N);
	int A[N];
	printf("Please input the numbers: \n");
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
	printf("Please choose an algorithm: 1 original, 2 better");
	scanf("%d", &sw);
	switch (sw)
	{
	case 1:
		MaxSum = origF(N, A);
	case 2:
		MaxSum = betterF(N, A);
	}
	printf("%d", MaxSum);
}

int origF(int N, int A[])
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

int betterF(int N, int A[])
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
