#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, item, choice, position, count;
    struct node *p, *q, *head, *pre_node, *next_node, *tail, *current_node;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    q = (struct node *)malloc(sizeof(struct node));
    printf("Enter the head element:");
    scanf("%d", &item);

    q->data = item;
    q->next = NULL;
    head = q;
    p = head;

    for (i = 1; i < n; i++)
    {
        q = (struct node *)malloc(sizeof(struct node));
        printf("Enter the element:");
        scanf("%d", &item);

        q->data = item;
        q->next = NULL;
        p->next = q;
        p = p->next;
    }
    p->next = head;
    p = head;
    while (p->next != head)
    {
        printf("%d ", p->data);
        p = p->next;
        tail = p;
    }
    printf("%d ", p->data);
    while (1)
    {
        printf("\n1.Insert the element at beginning\n2.Insert the element at middle\n3.Insert the element at end\n4.Delete the element at beginning\n5.Delete the element at middle\n6.Delete the element at end\n7.print all elements\n8.count\n9.Save the Reversed the list\n10.Display the reversed list\n11.escape\nEnter the choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            p = head;
            q = (struct node *)malloc(sizeof(struct node));
            printf("Enter the new head element:");
            scanf("%d", &item);

            q->data = item;
            q->next = NULL;
            tail->next = q;
            q->next = head;
            head = q;
            printf("The head element is %d\n", head->data);
            p = head;
            while (p->next != head)
            {
                printf("%d ", p->data);
                p = p->next;
            }
            printf("%d ", p->data);
        }
        else if (choice == 2)
        {
            printf("Enter the element which you want to insert:");
            scanf("%d", &item);
            q = (struct node *)malloc(sizeof(struct node));
            q->data = item;
            q->next = NULL;

            printf("Enter the position where you want to insert the element:");
            scanf("%d", &position);

            count = 0;
            p = head;
            while (p->next != head)
            {
                count = count + 1;
                p = p->next;
            }
            count++;
            printf("The count is %d\n", count);
            if (count < position)
            {
                printf("Invalid position");
            }
            else
            {
                p = head;
                i = 0;
                while (i < position - 1)
                {
                    pre_node = p;
                    p = p->next;
                    i++;
                }
                pre_node->next = q;
                q->next = p;
                p = head;
                while (p->next != head)
                {
                    printf("%d ", p->data);
                    p = p->next;
                }
                printf("%d ", p->data);
            }
        }

        else if (choice == 3)
        {
            p = head;

            q = (struct node *)malloc(sizeof(struct node));
            printf("Enter the element which you want to insert at end:");
            scanf("%d", &item);
            q->data = item;
            q->next = NULL;
            tail->next = q;
            tail = q;
            tail->next = head;
            while (p->next != head)
            {
                printf("%d ", p->data);
                p = p->next;
            }
            printf("%d ", p->data);
        }
        else if (choice == 4)
        {
            p = head;
            if (head == 0)
            {
                printf("The list is empty");
            }
            else
            {
                head = head->next;
                tail->next = head;
                free(p);
                p = head;
                if (head == 0)
                {
                    printf("The last element in the list also has been deleted");
                }
                else
                {
                    while (p->next != head)
                    {
                        printf("%d ", p->data);
                        p = p->next;
                    }
                    printf("%d ", p->data);
                }
            }
        }
        else if (choice == 5)
        {
            p = head;
            printf("Enter the position:");
            scanf("%d", &position);
            count = 0;
            while (p->next != head)
            {
                count++;
                p = p->next;
            }
            count++;
            printf("The number of element is %d\n", count);
            if (count < position)
            {
                printf("\nInvalid position");
            }
            else
            {
                p = head;
                i = 0;
                while (i < position - 1)
                {
                    pre_node = p;
                    p = p->next;
                    i++;
                }
                next_node = p->next;
                pre_node->next = NULL;
                p->next = NULL;
                free(p);
                pre_node->next = next_node;
                p = head;
                while (p->next != head)
                {
                    printf("%d ", p->data);
                    p = p->next;
                }
                printf("%d ", p->data);
            }
        }
        else if (choice == 6)
        {
            p = head;
            if (head == 0)
            {
                printf("The list is empty");
            }
            else
            {
                while (p->next != head)
                {
                    pre_node = p;
                    p = p->next;
                }
                pre_node->next = head;
                free(p);
                p = head;
                while (p->next != head)
                {
                    printf("%d ", p->data);
                    p = p->next;
                }
                printf("%d ", p->data);
            }
        }
        else if (choice == 7)
        {
            p = head;
            while (p->next != head)
            {
                printf("%d ", p->data);
                p = p->next;
            }
            printf("%d ", p->data);
        }
        else if (choice == 8)
        {
            p = head;
            if (p == 0)
            {
                printf("There is no element present");
            }
            else
            {
                while (p != tail)
                {
                    count++;
                    p = p->next;
                }
                count++;
                printf("The count is %d", count);
                count = 0;
            }
        }
        else if (choice == 9)
        {
            if (head == NULL)
            {
                printf("There is no element present");
            }
            else
            {
                current_node = tail->next;
                next_node = current_node->next;
                while (current_node != tail)
                {
                    pre_node = current_node;
                    current_node = next_node;
                    next_node = current_node->next;
                    current_node->next = pre_node;
                }
                next_node->next = tail;
                head = tail;
                tail = next_node;
                p = head;
                while (p != tail)
                {
                    printf("%d ", p->data);
                    p = p->next;
                }
                printf("%d", p->data);
            }
        }
        else if (choice == 10)
        {
            if (head == NULL)
            {
                printf("There is no element present");
            }
            else
            {
                current_node = tail->next;
                next_node = current_node->next;
                while (current_node != tail)
                {
                    pre_node = current_node;
                    current_node = next_node;
                    next_node = current_node->next;
                    current_node->next = pre_node;
                }
                next_node->next = tail;
                head = tail;
                tail = next_node;
                p = head;
                while (p != tail)
                {
                    printf("%d ", p->data);
                    p = p->next;
                }
                printf("%d", p->data);
                current_node = tail->next;
                next_node = current_node->next;
                while (current_node != tail)
                {
                    pre_node = current_node;
                    current_node = next_node;
                    next_node = current_node->next;
                    current_node->next = pre_node;
                }
                next_node->next = tail;
                head = tail;
                tail = next_node;
            }
        }
        else if (choice == 11)
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