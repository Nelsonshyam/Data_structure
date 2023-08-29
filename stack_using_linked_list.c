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

struct node *push(struct node *top)
{
    struct node *q;

    q = create();
    if (top == NULL)
    {
        top = q;
        return top;
    }
    else
    {
        q->next = top;
        top = q;
        return top;
    }
}

struct node *pop(struct node *top)
{
    struct node *p;
    p = top;
    if (top == NULL)
    {
        printf("The stack is empty\n");
    }
    else
    {
        top = top->next;
        free(p);
        return top;
    }
}

void peek(struct node *top)
{
    if (top == NULL)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The peek element is %d\n", top->data);
    }
}

void display(struct node *top)
{
    struct node *p;
    if (top == NULL)
    {
        printf("There stack is empty\n");
    }
    else
    {
        p = top;
        printf("The elements are ");
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    struct node *top = NULL;
    int choice;

    while (1)
    {
        printf("Choices:\n1.Push\n2.Pop\n3.peek\n4.Display\n5.escape\nEnter the choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            top = push(top);
        }
        else if (choice == 2)
        {
            top = pop(top);
        }
        else if (choice == 3)
        {
            peek(top);
        }
        else if (choice == 4)
        {
            display(top);
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
}