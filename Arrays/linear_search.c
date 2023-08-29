#include <stdio.h>

int linear_search(int n, int search, int arr[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int i, n, search, pos = -1, result, arr[50];
    printf("Enter the no of elements:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d:", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the search element:");
    scanf("%d", &search);

    result = linear_search(n, search, arr);
    if (pos != result)
    {
        printf("The element is found in the position of %d", result + 1);
    }
    else
    {
        printf("The element is not found");
    }

    return 0;
}