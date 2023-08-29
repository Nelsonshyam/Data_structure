#include <stdio.h>

int main()
{
    int n, stack1[100], stack2[100], top1 = -1, top2 = -1, element, count = 0, choice, i;

    printf("Enter the number of elements:");
    scanf("%d", &n);
    stack1[n], stack2[n];
    while (1)
    {
        printf("Choice:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Front\n5.Isempty\n6.size\n7.escape\nEnter the choice:");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter the element:");
            scanf("%d", &element);

            if (top1 == -1)
            {
                top1++;
                stack1[top1] = element;
            }
            else if (top1 == n - 1)
            {
                printf("The queue is full\n");
            }
            else
            {
                top1 = top1 + 1;
                stack1[top1] = element;
            }
        }

        if (choice == 2)
        {
            if (top1 == -1)
            {
                printf("The queue is empty\n");
            }
            else
            {
                while (top1 != -1)
                {
                    top2 = top2 + 1;
                    stack2[top2] = stack1[top1];
                    top1 = top1 - 1;
                }
                printf("The dequeue element is %d\n", stack2[top2]);
                top2 = top2 - 1;
                while (top2 != -1)
                {
                    top1 = top1 + 1;
                    stack1[top1] = stack2[top2];
                    top2 = top2 - 1;
                }
            }
        }

        else if (choice == 3)
        {
            if (top1 == -1)
            {
                printf("The queue is empty\n");
            }
            else
            {
                printf("The element in the queue are ");
                for (i = 0; i < top1 + 1; i++)
                {
                    printf("%d ", stack1[i]);
                }
                printf("\n");
            }
        }
        else if (choice == 4)
        {
            if (top1 == -1)
            {
                printf("The queue is empty\n");
            }
            else
            {
                while (top1 != -1)
                {
                    top2 = top2 + 1;
                    stack2[top2] = stack1[top1];
                    top1 = top1 - 1;
                }
                printf("The front element is %d\n", stack2[top2]);
                while (top2 != -1)
                {
                    top1 = top1 + 1;
                    stack1[top1] = stack2[top2];
                    top2 = top2 - 1;
                }
            }
        }
        else if (choice == 5)
        {
            if (top1 == n - 1)
            {
                printf("The queue is full\n");
            }
            else if (top1 == -1)
            {
                printf("The queue is empty\n");
            }
            else
            {
                printf("There are some elements are present here\n");
            }
        }
        else if (choice == 6)
        {
            if (top1 == -1)
            {
                printf("The queue is empty\n");
            }
            else
            {
                for (i = 0; i < top1 + 1; i++)
                {
                    count++;
                }
                printf("The queue elements are present are %d\n", count);
                count = 0;
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
}