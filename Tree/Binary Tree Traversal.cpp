#include <stdio.h>
struct TreeNode;
typedef TreeNode *BinTree;
struct TreeNode
{
	int Data;
	BinTree Left;
	BinTree Right;
};
void Preorder(BinTree BT);
void Inorder(BinTree BT);
void Postorder(BinTree BT);

int main()
{
	return 0;
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
