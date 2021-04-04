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
int Find(List PtrL, int X);
void Insert(int X, List PtrL, int Position); //在第Position个位置插入
void Delete(List PtrL, int Position);		 //第Position个位置删除

int main()
{
	int i, N, num, Position;
	List PtrL;
	PtrL = MakeEmpty();

	//建表
	printf("您想要输入几个元素？\n");
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &num);
		Insert(num, PtrL, i);
		//PtrL->Data[i-1] = num;
	}
	PtrL->Last = N - 1;

	//查找
	printf("您想要查找哪个元素？\n");
	scanf("%d", &num);
	if (Find(PtrL, num) < 0)
		printf("没有您要找的元素\n");
	else
		printf("这个元素在下标为%d的位置上\n", Find(PtrL, num));

	//插入
	printf("您想要将什么插入到第几个位置上？\n");
	scanf("%d %d", &num, &Position);
	Insert(num, PtrL, Position);

	//删除
	printf("您想要删除第几个元素？\n");
	scanf("%d", &Position);
	Delete(PtrL, Position);

	//输出
	printf("当前表中所剩元素为：\n");
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
		printf("数组已满！\n");
		return;
	}
	if (Position < 1 || Position > PtrL->Last + 2)
	{
		printf("插入位置不合法！\n");
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
		printf("删除位置不合法！\n");
		return;
	}
	for (i = Position - 1; i < PtrL->Last; i++)
		PtrL->Data[i] = PtrL->Data[i + 1];
	PtrL->Data[PtrL->Last] = 0;
	PtrL->Last--;
}