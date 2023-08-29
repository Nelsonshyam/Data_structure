#include <stdio.h>

int main()
{
    int row1, col1, row2, col2, i, j, k, mat1[50][50], mat2[50][50], result[50][50], choice;

    printf("Enter the no of rows:");
    scanf("%d", &row1);
    printf("Enter the no of columns:");
    scanf("%d", &col1);

    printf("Enter the no of rows:");
    scanf("%d", &row2);
    printf("Enter the no of columns:");
    scanf("%d", &col2);

    while (1)
    {
        printf("Choices:\n1.sum the matrix\n2.multiply the matirx\n3.Escape\nEnter the choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            if (row1 == row2 && col1 == col2)
            {
                printf("The matrix 1 is\n");
                for (i = 0; i < row1; i++)
                {
                    for (j = 0; j < col1; j++)
                    {
                        printf("Enter the row %d column %d:", i + 1, j + 1);
                        scanf("%d", &mat1[i][j]);
                    }
                }

                printf("The matrix 2 is\n");
                for (i = 0; i < row2; i++)
                {
                    for (j = 0; j < col2; j++)
                    {
                        printf("Enter the row %d column %d:", i + 1, j + 1);
                        scanf("%d", &mat2[i][j]);
                    }
                }

                printf("The matrix 1 is\n");
                for (i = 0; i < row1; i++)
                {
                    for (j = 0; j < col1; j++)
                    {
                        printf("%d ", mat1[i][j]);
                    }
                    printf("\n");
                }
                printf("The matrix 2 is\n");
                for (i = 0; i < row2; i++)
                {
                    for (j = 0; j < col2; j++)
                    {
                        printf("%d ", mat2[i][j]);
                    }
                    printf("\n");
                }

                printf("The sum of the matrix is is\n");
                for (i = 0; i < row2; i++)
                {
                    for (j = 0; j < col2; j++)
                    {
                        printf("%d ", mat1[i][j] + mat2[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else
            {
                printf("Invalid matrix");
            }
        }
        else if (choice == 2)
        {
            if (col1 == row2)
            {
                printf("The matrix 1 is\n");
                for (i = 0; i < row1; i++)
                {
                    for (j = 0; j < col1; j++)
                    {
                        printf("Enter the row %d column %d:", i + 1, j + 1);
                        scanf("%d", &mat1[i][j]);
                    }
                }

                printf("The matrix 2 is\n");
                for (i = 0; i < row2; i++)
                {
                    for (j = 0; j < col2; j++)
                    {
                        printf("Enter the row %d column %d:", i + 1, j + 1);
                        scanf("%d", &mat2[i][j]);
                    }
                }

                printf("The matrix 1 is\n");
                for (i = 0; i < row1; i++)
                {
                    for (j = 0; j < col1; j++)
                    {
                        printf("%d ", mat1[i][j]);
                    }
                    printf("\n");
                }
                printf("The matrix 2 is\n");
                for (i = 0; i < row2; i++)
                {
                    for (j = 0; j < col2; j++)
                    {
                        printf("%d ", mat2[i][j]);
                    }
                    printf("\n");
                }
                for (i = 0; i < row1; i++)
                {
                    for (j = 0; j < col2; j++)
                    {
                        result[i][j] = 0;
                        for (k = 0; k < col2; k++)
                        {
                            result[i][j] += mat1[i][k] * mat2[k][j];
                        }
                    }
                }
                printf("The matrix multiplication is \n");
                for (i = 0; i < row1; i++)
                {
                    for (j = 0; j < col2; j++)
                    {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                printf("Invalid matrix\n");
            }
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            printf("You were entered the wrong option, please enter the correct option\n");
        }
    }
    return 0;
}