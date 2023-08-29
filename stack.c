#include <stdio.h>

int main()
{
    int stack[100], choice, top = -1, n, element, temp, count = 0;
    printf("Enter the number of elements going to enter:");
    scanf("%d", &n);

    while (1)
    {
        printf("Enter the choice 1.Push 2.Pop 3.peek 4.Show 5.isempty 6.size 7.escape:");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter the element:");
            scanf("%d", &element);
            if (top == -1)
            {
                top = top + 1;
                stack[top] = element;
            }
            else if (top == n - 1)
            {
                printf("The stack is filled\n");
            }
            else if (top != -1)
            {
                top = top + 1;
                stack[top] = element;
            }
            temp = top;
        }
        else if (choice == 2)
        {
            if (top == -1)
            {
                printf("The stack is empty\n");
            }
            else if (top != -1)
            {
                top = top - 1;
            }
            temp = top;
        }

        else if (choice == 3)
        {
            if (top == -1)
            {
                printf("The stack is empty\n");
            }
            else if (top == n - 1)
            {
                printf("The stack is filled");
            }
            else
            {
                printf("Top of the element is %d\n", stack[top]);
            }
        }
        else if (choice == 4)
        {
            if (top == -1)
            {
                printf("The stack is empty\n");
            }
            else
            {
                while (top != -1)
                {
                    printf("%d ", stack[top]);
                    top = top - 1;
                }
                printf("\n");
                top = temp;
            }
        }
        else if (choice == 5)
        {
            if (top == n - 1)
            {
                printf("The stack is filled");
            }
            else if (top == -1)
            {
                printf("The stack is empty");
            }
            else
            {
                printf("The stack contains some numbers\n");
            }
        }
        else if (choice == 6)
        {
            int p = 0;
            if (top == -1)
            {
                printf("The stack is empty");
            }
            else
            {
                while (p != top)
                {
                    count++;
                    p++;
                }
                printf("The stack contains %d elements\n", count + 1);
            }
        }
        else if (choice == 7)
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