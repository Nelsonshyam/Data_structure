#include <stdio.h>

int particular(int arr[], int a)
{
    printf("The element in the position %d is %d", a, arr[a - 1]);
}

int some_set(int arr[], int x, int y, int i)
{
    for (i = x - 1; i < y; i++)
    {
        printf("%d ", arr[i]);
    }
}

int all_elements(int arr[], int i, int n)
{
    printf("The elements are ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int max_min(int arr[], int i, int n)
{
    int min, max;
    min = max = arr[0];
    for (i = 0; i < n; i++)
    {
        if (max <= arr[i])
        {
            max = arr[i];
        }
        if (min >= arr[i])
        {
            min = arr[i];
        }
    }
    printf("The maximum element from the array is %d and the minimum element is %d", max, min);
}

int sum_and_avg(int arr[], int i, int n)
{
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    printf("The sum:%d\n", sum);
    float average = sum;
    printf("The average:%.3f", average / n);
}

int reverse(int arr[], int i, int j, int n)
{
    int reverse[59];
    j = 0;
    i = n - 1;
    while (i >= 0)
    {
        reverse[j] = arr[i];
        i--;
        j++;
    }
    printf("The reversed elements are:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", reverse[i]);
    }
}

int rotate(int arr[], int i, int j, int n, int a)
{
    int rotate[50];
    j = n - a;
    for (i = 0; i < n; i++)
    {
        if (i < a)
        {
            rotate[j] = arr[i];
            j++;
        }
    }
    j = 0;
    for (i = a; i < n; i++)
    {
        rotate[j] = arr[i];
        j++;
    }
    printf("The elements are ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", rotate[i]);
    }
}

int duplicate_elements(int arr[], int i, int j, int n)
{
    int count = 0;
    int duplicate[50];
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                duplicate[i] = arr[j];
                count++;
            }
        }
    }
    if (count == 0)
    {
        printf("There is no duplicate elements");
    }
    else
    {
        printf("The duplicate elements are ");
        for (i = 0; i < count; i++)
        {
            printf("%d ", duplicate[i]);
        }
    }
}

int main()
{
    int i, n, a, choice, x, y, j, arr[50];
    printf("Enter the number of elements:");
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

    while (1)
    {
        printf("\nchoice:\n1.print particular element\n2.print some set of element\n3.print all element\n4.Finding maximum and minimum element\n5.Find sum and average\n6.print reverse element\n7.rotate the position of elements\n8.print duplicate elements\n9.escape");
        printf("\nEnter the choice:");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter the element position which you wants to display:");
            scanf("%d", &a);
            particular(arr, a);
        }
        else if (choice == 2)
        {
            printf("Enter the starting element position:");
            scanf("%d", &x);
            printf("Enter the starting element position:");
            scanf("%d", &y);
            printf("The element from %d to %d is ", x, y);
            some_set(arr, x, y, i);
        }
        else if (choice == 3)
        {
            all_elements(arr, i, n);
        }
        else if (choice == 4)
        {
            max_min(arr, i, n);
        }
        else if (choice == 5)
        {
            sum_and_avg(arr, i, n);
        }
        else if (choice == 6)
        {
            reverse(arr, i, j, n);
        }
        else if (choice == 7)
        {
            printf("Enter the position from where you want to move:");
            scanf("%d", &a);
            rotate(arr, i, j, n, a);
        }
        else if (choice == 8)
        {
            duplicate_elements(arr, i, j, n);
        }
        else if (choice == 9)
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