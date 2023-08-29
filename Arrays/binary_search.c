#include <stdio.h>

int binary_search(int n, int search, int arr[], int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == search)
        {
            return mid;
        }
        else if (search <= mid)
        {
            high = mid - 1;
        }
        else if (search >= mid)
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int i, n, search, result, pos = -1, arr[50];

    printf("Enter the no of elements:");
    scanf("%d", &n);
    int low = 0, high = n;

    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d:", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the search element:");
    scanf("%d", &search);

    result = binary_search(n, search, arr, low, high);
    if (result != pos)
    {
        printf("The element is found in the position %d", result + 1);
    }
    else
    {
        printf("The element is not found");
    }
}