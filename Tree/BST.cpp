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

struct TreeNode
{
	int Data;
	BinTree Left;
	BinTree Right;
};

int main()
{
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
