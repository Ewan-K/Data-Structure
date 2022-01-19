#include <stdio.h>
#include <stdlib.h>
//输入N个数，返回AVL的根节点

typedef struct treeNode *Tree;
struct treeNode
{
    int a;
    Tree Left, Right;
};

int main()
{
    int M;
    Tree Tree;
    scanf("%d", &M);
    Tree = makeTree(M);
    printf("%d\n", Tree->a);
    return 0;
}

Tree makeTree(int N);
Tree emptyNode(int a);
Tree insert(int a, Tree Tree);
int height(Tree Tree);
Tree LL(Tree Tree);
Tree LR(Tree Tree);
Tree RR(Tree Tree);
Tree RL(Tree Tree);

Tree makeTree(int N)
{
    int a;
    int _;
    scanf("%d", &a);
    Tree Tree = emptyNode(a);
    for (_ = 1; _ < N; _++)
    {
        scanf("%d", &a);
        Tree = insert(a, Tree);
    }
    return Tree;
}

Tree emptyNode(int a)
{
    Tree T = (Tree)malloc(sizeof(treeNode));
    T->a = a;
    T->Left = T->Right = NULL;
    return T;
}

Tree insert(int a, Tree Tree)
{
    if (!Tree)
        Tree = emptyNode(a);
    else
    {
        if (a < Tree->a)
        {
            Tree->Left = insert(a, Tree->Left);
            if (height(Tree->Left) - height(Tree->Right) == 2)
            {
                if (a < Tree->Left->a)
                    Tree = LL(Tree);
                else
                    Tree = LR(Tree);
            }
        }
        else
        {
            Tree->Right = insert(a, Tree->Right);
            if (height(Tree->Right) - height(Tree->Left) == 2)
            {
                if (a < Tree->Right->a)
                    Tree = RL(Tree);
                else
                    Tree = RR(Tree);
            }
        }
    }
    return Tree;
}

int height(Tree Tree)
{
    int leftH, rightH, max;
    if (Tree)
    {
        leftH = height(Tree->Left);
        rightH = height(Tree->Right);
        max = leftH > rightH ? leftH : rightH;
        return max + 1;
    }
    else
        return 1;
}