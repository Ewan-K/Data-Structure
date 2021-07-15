#include <stdio.h>

int main()
{
	int N, i;
	printf("How many numbers?\n");
	scanf("%d", &N);
	int A[N];
	printf("Please input the numbers: \n");
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int ThisSum, MaxSum = 0;

	for (i = 0; i < N; i++)
	{
		ThisSum += A[i];
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)
			ThisSum = 0;
	}
	printf("%d", MaxSum);
}
