#include <stdio.h>

int insertion_sort(int n, int arr[])
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int i, n, arr[50];
    printf("Enter the no of element:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d:", i + 1);
        scanf("%d", &arr[i]);
    }

    insertion_sort(n, arr);
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}