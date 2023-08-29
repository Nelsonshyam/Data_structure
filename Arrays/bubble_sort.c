#include <stdio.h>

int bubble_sort(int n, int arr[])
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int i, n, result, arr[50];
    printf("Enter the no of elements:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d:", i + 1);
        scanf("%d", &arr[i]);
    }

    result = bubble_sort(n, arr);
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}