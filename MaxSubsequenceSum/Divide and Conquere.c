#include <stdio.h>

int MaxSubSum(int A[], int left, int right);
int Max3(int A, int B, int C);

int main()
{
	int N, i;

	scanf("%d", &N);
	int A[N];
	for (i = 0; i <= N; i++)
		scanf("%d", &A[i]);

	printf("%d", MaxSubSum(A, 0, N - 1));
}

int MaxSubSum(int A[], int left, int right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	int center, i;
	int left, right;

	center = (left + right) / 2;
	/* Base case */
	if (left == right)
		if (A[left] > 0)
			return A[left];
		else
			return 0;

	MaxLeftSum = MaxSubSum(A, left, center);
	MaxRightSum = MaxSubSum(A, center + 1, right);

	MaxLeftBorderSum = 0;
	LeftBorderSum = 0;
	for (i = center; i >= left; i--)
	{
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for (i = center + 1; i <= right; i++)
	{
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int Max3(int A, int B, int C)
{
	if (A < B)
		if (B <= C)
			return C;
		else
			return B;
	else if (A < C)
		return C;
	else
		return A;
}