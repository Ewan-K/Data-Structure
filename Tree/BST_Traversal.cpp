#include <stdio.h>
#include <stdlib.h>
#include <stack>
// 二叉树的DFS包括先序遍历、中序遍历、后序遍历，BFS是层序遍历
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode
{
	int Data;
	BinTree Left;  // 左孩子
	BinTree Right; // 右孩子
};

Position Find(int X, BinTree BST);
Position IterationFind(int X, BinTree BST);
Position FindMax(BinTree BST);
Position FindMin(BinTree BST);
Position Insert(int X, BinTree BST);
Position Delete(int X, BinTree);
void Preorder(BinTree BT);
void Preorder_in_Stack(BinTree BT);
void Inorder(BinTree BT);
void Postorder(BinTree BT);
void Postorder_in_Stack(BinTree BT);

int main()
{
	BinTree BST = NULL;
	BST = Insert(3, BST);
	BST = Insert(1, BST);
	BST = Insert(0, BST);
	BST = Insert(2, BST);
	BST = Insert(4, BST);
	BST = Insert(5, BST);
	Preorder(BST);
	Preorder_in_Stack(BST);
	printf("\n");
	Postorder(BST);
	Postorder_in_Stack(BST);
	printf("\n");

	BST = Delete(1, BST);
	Preorder(BST);
	printf("\n");
	printf("%d\n", FindMax(BST)->Data);
	getchar();
	return 0;
}

// RecursionFind
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

// Recursion
Position FindMax(BinTree BST)
{
	if (!BST)
		return NULL;
	else if (!BST->Right)
		return BST;
	else
		return FindMax(BST->Right);
	/*
	while (BST)
	{
		if (!BST->Right)
			return BST;
		else
			BST = BST->Right;
	}
	return NULL;
	*/
	/*
	if (BST)
		while (BST->Right)
			BST = BST->Right;
	return BST;
	*/
}

// Iteration
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
	else if (X > BST->Data)
		BST->Right = Insert(X, BST->Right);
	// else
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

void Preorder_in_Stack(BinTree BT)
{
	std::stack<BinTree> s;
	s.push(BT);
	while (!s.empty())
	{
		BinTree tmp = s.top();
		s.pop();
		if (tmp) // s这个堆栈中有可能插入nullptr，tmp判空
		{
			printf("%d", tmp->Data);
			s.push(tmp->Right);
			s.push(tmp->Left);
		}
	}
}

void Inorder(BinTree BT)
{
	if (BT)
	{
		Inorder(BT->Left);
		printf("%d", BT->Data);
		Inorder(BT->Right);
	}
}

void Postorder(BinTree BT)
{
	if (BT)
	{
		Postorder(BT->Left);
		Postorder(BT->Right);
		printf("%d", BT->Data);
	}
}

void Postorder_in_Stack(BinTree BT)
{
	std::stack<BinTree> s1, s2;
	BinTree cur = BT;
	// 当右子树全都压栈后，我们需要从根节点开始重新向左遍历，这时只用一个栈无法解决数据的保存和树的向上回溯，所以我们选择采用2个栈来解决
	// 与Preorder不同，这里先得到弹出时为后序遍历顺序的堆栈，中途不弹出任何节点
	// 算法解释：
	/*
	1.从根节点开始，不断搜索右子节点，把节点压入栈1和栈2，直到右子节点为空。
	2.弹出栈1的顶端的节点。
	3.将节点指向弹出结点的左子树。然后再从步骤1开始，直到栈1为空并且当前节点为空。
	*/
	while (cur || !s1.empty()) // 和上方的Preorder不同，这里堆栈中根本不放入nullptr
	{
		while (cur)
		{
			s1.push(cur);
			s2.push(cur);
			cur = cur->Right;
		}
		cur = s1.top();
		s1.pop();
		cur = cur->Left;
	}
	while (!s2.empty())
	{
		printf("%d", s2.top()->Data);
		s2.pop();
	}
}