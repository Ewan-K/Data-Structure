#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef struct LNode *List;
struct LNode
{
	int Data[MAXSIZE];
	int Last;
};

List MakeEmpty();
int Find(List PtrL, int X);					 // 寻找值
void Insert(int X, List PtrL, int Position); // 在第Position个位置插入
void Delete(List PtrL, int Position);		 // 第Position个位置删除

int main()
{
	int i, N, num, Position;
	List PtrL;
	PtrL = MakeEmpty();

	// 建表
	printf("How many numbers?\n");
	scanf("%d", &N);
	printf("Please input the numbers: \n");
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &num);
		Insert(num, PtrL, i); // PtrL->Data[i-1] = num;
	}
	PtrL->Last = N - 1;

	// 查找
	printf("What is the value of the number to find?\n");
	scanf("%d", &num);
	if (Find(PtrL, num) < 0)
		printf("The number doesn't exist in the list.\n");
	else
		printf("This number is located at %d\n", Find(PtrL, num));

	// 插入
	printf("What is the number you want to insert and where?\n");
	scanf("%d %d", &num, &Position);
	Insert(num, PtrL, Position);

	// 删除
	printf("Which number do you want to delete?\n");
	scanf("%d", &Position);
	Delete(PtrL, Position);

	// 输出
	printf("The list contains:\n");
	for (i = 0; i <= PtrL->Last; i++)
		printf("%d	", PtrL->Data[i]);

	getchar();
	getchar();
}

List MakeEmpty()
{
	List PtrL;
	PtrL = (List)malloc(sizeof(LNode));
	PtrL->Last = -1;
	return PtrL;
}
int Find(List PtrL, int X)
{
	int i;
	for (i = 0; i <= PtrL->Last; i++)
	{
		if (PtrL->Data[i] == X)
			break;
	}
	/*
	while (i <= PtrL->Last && PtrL->Data[i] != X)
	i++;
	*/
	if (i > PtrL->Last)
		return -1;
	else
		return i;
}
void Insert(int X, List PtrL, int Position)
{
	int i;
	if (PtrL->Last == MAXSIZE - 1)
	{
		printf("The list if full!\n");
		return;
	}
	if (Position < 1 || Position > PtrL->Last + 2)
	{
		printf("This position is illegal!\n");
		return;
	}
	for (i = PtrL->Last; i >= Position - 1; i--)
		PtrL->Data[i + 1] = PtrL->Data[i];
	PtrL->Data[Position - 1] = X;
	PtrL->Last++;
	return;
}
void Delete(List PtrL, int Position)
{
	int i;
	if (Position < 1 || Position > PtrL->Last)
	{
		printf("This position is illegal!\n");
		return;
	}
	for (i = Position - 1; i < PtrL->Last; i++)
		PtrL->Data[i] = PtrL->Data[i + 1];
	PtrL->Data[PtrL->Last] = 0;
	PtrL->Last--;
}