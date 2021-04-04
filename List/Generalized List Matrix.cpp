#include <stdio.h>
#include <stdlib.h>

typedef struct GNode *Matrix;
struct Term
{
    int row;
    int col;
    int value;
};
struct GNode
{
    int tag;
    union {
        Term term;
        Matrix next;
    } region;
    Matrix down;
    Matrix right;
};

Matrix createEmpty(void);

int main()
{
    Matrix matrix = createEmpty();
    printf("%d %d %d %d", matrix->tag, matrix->region.term.row, matrix->region.term.col, matrix->region.term.value);
    getchar();
    getchar();
}

Matrix createEmpty(void)
{
    Matrix matrix;
    Term term;
    term.row = 0;
    term.col = 0;
    term.value = 0;

    matrix = (Matrix)malloc(sizeof(struct GNode));
    matrix->tag = 1;
    matrix->region.term = term;
    matrix->down = NULL;
    matrix->right = NULL;
    return matrix;
}