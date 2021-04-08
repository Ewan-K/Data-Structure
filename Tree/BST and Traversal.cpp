#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef TreeNode *BinTree;
typedef BinTree Position;
Position Find(int X, BinTree BST);
Position IterationFind(int X, BinTree BST);
Position FindMax(BinTree BST);
Position FindMin(BinTree BST);
Position Insert(int X, BinTree BST);
Position Delete(int X, BinTree);
void Preorder(BinTree BT);
void Inorder(BinTree BT);
void Postorder(BinTree BT);

struct TreeNode
{
	int Data;
	BinTree Left;
	BinTree Right;
};

int main()
{
	BinTree BST = NULL;
	BST = Insert(0, BST);
	BST = Insert(1, BST); // 目前仍不能显示正确结果
	// BST = Insert(2, BST);
	// BST = Insert(3, BST);
	// BST = Insert(4, BST);
	// BST = Insert(5, BST);
	Preorder(BST);
	getchar();
	return 0;
}

//Recursion
Position Find(int X, BinTree BST)
{
	if (!BST)
		return NULL;
	else if (X < BST->Data)
		return Find(X, BST->Left);
	else if (X > BST->Data)
		return Find(X, BST->Right);
	else
		return BST;
}

Position IterationFind(int X, BinTree BST)
{
	while (BST)
	{
		if (X < BST->Data)
			BST = BST->Left;
		else if (X > BST->Data)
			BST = BST->Right;
		else
			return BST;
	}
	return NULL;
}
//Recursion
Position FindMax(BinTree BST)
{
	if (!BST)
		return NULL;
	else if (!BST->Right)
		return BST;
	else
		return FindMax(BST->Right);
}
//Iteration
Position FindMin(BinTree BST)
{
	while (BST)
	{
		if (!BST->Left)
			return BST;
		else
			BST = BST->Left;
	}
	return NULL;
	/*
	if (BST)
		while (BST->Left)
			BST = BST->Left;
	return BST;
	*/
}

BinTree Insert(int X, BinTree BST)
{
	if (!BST)
	{
		BST = (BinTree)malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else if (X < BST->Data)
		BST->Left = Insert(X, BST->Left);
	else if (BST->Data > X)
		BST->Right = Insert(X, BST->Right);
	return BST;
}

Position Delete(int X, BinTree BST)
{
	BinTree Tmp;
	if (X < BST->Data)
		BST->Left = Delete(X, BST->Left);
	else if (X > BST->Data)
		BST->Right = Delete(X, BST->Right);
	else
	{
		if (BST->Left && BST->Right)
		{
			Tmp = FindMin(BST->Right);
			BST->Data = Tmp->Data;
			BST->Right = Delete(Tmp->Data, BST->Right);
		}
		else
		{
			Tmp = BST;
			if (!BST->Left)
				BST = BST->Right;
			else if (!BST->Right)
				BST = BST->Left;
			free(Tmp);
		}
	}
	return BST;
}

void Preorder(BinTree BT)
{
	if (BT)
	{
		printf("%d", BT->Data);
		Preorder(BT->Left);
		Preorder(BT->Right);
	}
}
void Inorder(BinTree BT)
{
	if (BT)
	{
		Preorder(BT->Left);
		printf("%d", BT->Data);
		Preorder(BT->Right);
	}
}

void Postorder(BinTree BT)
{
	if (BT)
	{
		Preorder(BT->Left);
		Preorder(BT->Right);
		printf("%d", BT->Data);
	}
}