#include <stdio.h>

int insert(int arr[], int n)
{
    int pos, element, i;
    printf("Enter the position:");
    scanf("%d", &pos);
    if (pos <= 0 || pos > n)
    {
        printf("invalid position\n");
    }
    else
    {
        n++;
        printf("Enter the element:");
        scanf("%d", &element);
        for (i = n - 1; i >= pos - 1; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[pos - 1] = element;
    }
    return n;
}

int insert_end(int arr[], int n)
{
    int element;
    printf("Enter the elemnt:");
    scanf("%d", &element);
    arr[n] = element;
    n++;
    return n;
}

int delete(int arr[], int n)
{
    int pos, i;
    printf("Enter the position:");
    scanf("%d", &pos);
    if (pos <= 0 || pos > n)
    {
        printf("invalid position\n");
    }
    else
    {
        for (i = pos; i <= n; i++)
        {
            arr[i - 1] = arr[i];
        }
        n--;
    }
    return n;
}

void display(int arr[], int n)
{
    int i;
    printf("The elements are ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int i, pos, n, arr[50], choice, element;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the element%d:", i + 1);
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("Choices:\n1.Insert\n2.Insert at end\n3.Delete\n4.Display\n5.Escape\nEnter the choice:");
        scanf("%d", &choice);

        if (choice == 1)
        {
            n = insert(arr, n);
        }
        else if (choice == 2)
        {
            n = insert_end(arr, n);
        }
        else if (choice == 3)
        {
            n = delete (arr, n);
        }
        else if (choice == 4)
        {
            display(arr, n);
        }
        else if (choice == 5)
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