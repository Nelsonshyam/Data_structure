#include <stdio.h>
int main()
{
    int choice, rear = -1, front = -1, n, element, i, queue[100], p = 0, count = 0;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    while (1)
    {
        printf("Enter the choice 1.enqueue 2.dequeue 3.display 4.front 5.isempty 6.size 7.escape:");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter the element:");
            scanf("%d", &element);
            if (rear == -1 && front == -1)
            {
                front = rear = 0;
                queue[rear] = element;
            }
            else if (rear == n - 1)
            {
                printf("The queue is full\n");
            }
            else
            {
                rear = rear + 1;
                queue[rear] = element;
            }
        }
        else if (choice == 2)
        {
            if (rear == -1 && front == -1)
            {
                printf("The queue is empty\n");
            }
            else if ((front == rear) && !(front == -1 && rear == -1))
            {
                front = rear = -1;
            }
            else
            {
                front++;
            }
        }
        else if (choice == 3)
        {
            if (rear == -1 && front == -1)
            {
                printf("The queue is empty\n");
            }
            else
            {
                for (i = front; i < rear + 1; i++)
                {
                    printf("%d ", queue[i]);
                }
                printf("\n");
            }
        }
        else if (choice == 4)
        {
            if (rear == -1 && front == -1)
            {
                printf("The queue is empty\n");
            }
            else
            {
                printf("%d", queue[front]);
            }
            printf("\n");
        }
        else if (choice == 5)
        {
            if (rear == -1 && front == -1)
            {
                printf("The queue is empty\n");
            }
            else if (rear == n - 1)
            {
                printf("The queue is filled\n");
            }
            else
            {
                printf("The queue contains some number\n");
            }
        }
        else if (choice == 6)
        {
            if (rear == -1 && front == -1)
            {
                printf("The queue is empty\n");
            }
            else
            {
                while (p != rear)
                {
                    count++;
                    p++;
                }
                printf("The size of the queue is %d\n", count + 1);
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