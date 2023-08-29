#include <stdio.h>

int main()
{
    int n, i, queue[100], front = -1, rear = -1, element, choice, p = 0, count = 0;

    printf("Enter the number of elements:");
    scanf("%d", &n);
    queue[n];

    while (1)
    {
        printf("Choices\n1.enqueue\n2.dequeue\n3.display\n4.front\n5.isempty\n6.size\n7.escape\nEnter the choice:");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter the element:");
            scanf("%d", &element);

            if (front == -1 && rear == -1)
            {
                front = rear = 0;
                queue[rear] = element;
            }
            else if ((rear + 1) % n == front)
            {
                printf("The queue is Filled\n");
            }
            else
            {
                rear = (rear + 1) % n;
                queue[rear] = element;
            }
        }

        else if (choice == 2)
        {
            if (front == -1 && rear == -1)
            {
                printf("The queue is empty\n");
            }
            else if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % n;
                printf("The element has been removed\n");
            }
        }

        else if (choice == 3)
        {
            if (front == -1 && rear == -1)
            {
                printf("The queue is empty\n");
            }
            else
            {
                printf("The element in the queue are ");
                i = front;
                while (i != rear)
                {
                    printf("%d ", queue[i]);
                    i = (i + 1) % n;
                }
                printf("%d\n", queue[i]);
            }
        }

        else if (choice == 4)
        {
            if (front == -1 && rear == -1)
            {
                printf("The queue is empty\n");
            }
            else
            {
                printf("%d\n", queue[front]);
            }
        }

        else if (choice == 5)
        {
            if (front == -1 && rear == -1)
            {
                printf("The queue is empty\n");
            }
            else if ((rear + 1) % n == front)
            {
                printf("The queue is filled\n");
            }
            else
            {
                printf("There are some elements contain in the queue\n");
            }
        }

        else if (choice == 6)
        {
            if (front == -1 && rear == -1)
            {
                printf("The queue is empty\n");
            }
            else
            {
                i = front;
                while (i != rear)
                {
                    count++;
                    i = (i + 1) % n;
                }
                printf("The size occupied is %d\n", count + 1);
                count = 0;
                i = front;
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