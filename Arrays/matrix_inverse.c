#include <stdio.h>

int main()
{
    int mat[50][50], result[50][50], i, j, row, col;

    printf("Enter the no of rows:");
    scanf("%d", &row);
    printf("Enter the no of columns:");
    scanf("%d", &col);

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("Enter the row %d column %d:", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("The matrix is \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            result[i][j] = mat[j][i];
        }
    }
    printf("The inversion matrix is\n");
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}