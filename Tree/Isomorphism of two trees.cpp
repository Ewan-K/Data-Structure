// 若两棵树的根节点、左右子树通过交换后可以相等，则两棵树同构
/*(未测试)
8
A 1 2
B 3 4
C 5 -
D - -
E 6 -
G 7 -
F - -
H - -
8
G - 4
B 7 6
F - -
A 5 1
H - -
C 0 -
D - -
E 2 -
*/
#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

// 采用静态链表（一种体现链表思想的数组）存储二叉树
struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
} T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode[]);
int Isomorphic(Tree R1, Tree R2);

int main()
{
    Tree R1, R2;
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if (Isomorphic(R1, R2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

Tree BuildTree(struct TreeNode T[])
{
    int N;
    ElementType cl, cr;
    int Root;
    scanf("%d\n", &N);
    int check[N];
    if (N)
    {
        for (int i = 0; i < N; i++)
            check[i] = 0;

        for (int i = 0; i < N; i++)
        {
            scanf("%c %c %c\n", &T[i].Element, &cl, &cr);
            if (cl != '-')
            {
                T[i].Left = cl - '0';
                check[T[i].Left] = 1;
            }
            else
                T[i].Left = Null;
            if (cr != '-')
            {
                T[i].Right = cl - '0';
                check[T[i].Right] = 1;
            }
            else
                T[i].Right = Null;
        }
        for (int i = 0; i < N; i++)
        {
            if (!check[i])
            {
                Root = i;
                break;
            }
        }
    }
    return Root;
}

int Isomorphic(Tree R1, Tree R2)
{
    if ((R1 == Null) && (R2 == Null))
    {
        return 1;
    }
    if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
    {
        return 0;
    }
    if (T1[R1].Element != T2[R2].Element) // roots are different
    {
        return 0;
    }
    if ((T1[R1].Left == Null) && (T2[R2].Left == Null)) // both have no left subtree
    {
        return Isomorphic(T1[R1].Right, T2[R2].Right);
    }
    if ((T1[R1].Right == Null) && (T2[R2].Right == Null)) // both have no right subtree
    {
        return Isomorphic(T1[R1].Left, T2[R2].Left);
    }
    if ((T1[R1].Left != Null) && (T2[R2].Left != Null) && (T1[T1[R1].Left].Element == T2[T2[R2].Left].Element)) // no need to swap
    {
        return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
    }
    else // need to swap
        return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
}