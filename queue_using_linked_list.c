#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create()
{
    struct node *q;
    int item;
    q = (struct node *)malloc(sizeof(struct node));

    printf("Enter the element:");
    scanf("%d", &item);

    q->data = item;
    q->next = NULL;
    return q;
}

void enqueue(struct node **front, struct node **rear)
{
    struct node *q;
    if ((*front == NULL) && (*rear == NULL))
    {
        q = create();
        *front = *rear = q;
    }
    else
    {
        q = create();
        (*rear)->next = q;
        *rear = q;
    }
}

void dequeue(struct node **front, struct node **rear)
{
    struct node *p;
    p = *front;
    if ((*front == NULL) && (*rear == NULL))
    {
        printf("The queue is empty\n");
    }
    else if (*front == *rear)
    {
        *front = *rear = NULL;
    }
    else
    {
        *front = (*front)->next;
        free(p);
        p = *front;
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void display(struct node *front, struct node *rear)
{
    struct node *p;
    p = front;
    if ((front == NULL) && (rear == NULL))
    {
        printf("The queue is empty\n");
    }
    else
    {
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void front_value(struct node *front, struct node *rear)
{
    if ((front == NULL) && (rear == NULL))
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The front value is %d\n", front->data);
    }
}

void isempty(struct node *front, struct node *rear)
{
    if ((front == NULL) && (rear == NULL))
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The queue has some elements\n");
    }
}

void size(struct node *front, struct node *rear)
{
    int count = 0;
    struct node *p;
    p = front;
    if ((front == NULL) && (rear == NULL))
    {
        printf("The queue is empty\n");
    }
    else
    {
        while (p != NULL)
        {
            count++;
            p = p->next;
        }
        printf("The number of elements are %d\n", count);
        count = 0;
    }
}

int main()
{
    struct node *front = NULL, *rear = NULL;
    int choice;

    while (1)
    {
        printf("choice\n1.enqueue\n2.dequeue\n3.display\n4.front\n5.isempty\n6.size\n7.escape\nEnter the choice:");
        scanf("%d", &choice);

        if (choice == 1)
        {
            enqueue(&front, &rear);
        }
        else if (choice == 2)
        {
            dequeue(&front, &rear);
        }
        else if (choice == 3)
        {
            display(front, rear);
        }
        else if (choice == 4)
        {
            front_value(front, rear);
        }
        else if (choice == 5)
        {
            isempty(front, rear);
        }
        else if (choice == 6)
        {
            size(front, rear);
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