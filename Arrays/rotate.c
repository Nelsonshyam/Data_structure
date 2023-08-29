#include <stdio.h>
int main()
{
    int i, n, a, j, arr[50];
    printf("Enter the element no of elements:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the element%d:", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("The elements are ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("The dublicate elements are ");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] = j)
            {
                printf("%d ", arr[i]);
            }
        }
    }
    return 0;
}