#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
};

int main()
{
  int n, i, item, choice, position, count;
  struct node *p, *q, *head, *pre_node, *next_node, *tail;

  printf("Enter the number of elements:");
  scanf("%d", &n);

  q = (struct node *)malloc(sizeof(struct node));
  printf("Enter the head element:");
  scanf("%d", &item);

  q->data = item;
  q->next = NULL;
  q->prev = NULL;
  head = q;
  p = head;

  for (i = 1; i < n; i++)
  {
    q = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element:");
    scanf("%d", &item);

    q->data = item;
    q->next = NULL;
    q->prev = NULL;
    p->next = q;
    q->prev = p;
    p = p->next;
  }
  p->next = head;
  head->prev = p;
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
    printf("\n1.Insert the element at beginning\n2.Insert the element at middle\n3.Insert the element at end\n4.Delete the element at beginning\n5.Delete the element at middle\n6.Delete the element at end\n7.print all elements\n8.print elements at reverse order\n9.escape\nEnter the choice:");
    scanf("%d", &choice);
    if (choice == 1)
    {
      p = head;
      q = (struct node *)malloc(sizeof(struct node));
      printf("Enter the new head element:");
      scanf("%d", &item);

      q->data = item;
      q->next = NULL;
      q->prev = NULL;
      q->next = p;
      p->prev = q;
      tail->next = q;
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
      q->prev = NULL;

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
        q->prev = pre_node;
        q->next = p;
        p->prev = q;
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
      q = (struct node *)malloc(sizeof(struct node));
      printf("Enter the element which you want to insert at end:");
      scanf("%d", &item);
      q->data = item;
      q->next = NULL;
      q->prev = NULL;
      tail->next = q;
      q->prev = tail;
      tail = q;
      tail->next = head;
      p = head;
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
      else if (head->next == head)
      {
        head = tail = NULL;
        free(p);
      }
      else
      {
        head = head->next;
        head->prev = tail;
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
      if (head == 0)
      {
        printf("The list is empty");
      }
      else
      {
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
          next_node->prev = pre_node;
          pre_node->next = next_node;
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
    }
    else if (choice == 6)
    {
      p = tail;
      if (head == 0)
      {
        printf("The list is empty");
      }
      else if (head->next == NULL)
      {
        head = tail = NULL;
        free(p);
      }
      else
      {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(p);
        p = head;
        if (p == 0)
        {
          printf("The list is empty");
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
    else if (choice == 7)
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
          printf("%d ", p->data);
          p = p->next;
        }
        printf("%d ", p->data);
      }
    }
    else if (choice == 8)
    {
      if (head == 0)
      {
        printf("The list is empty");
      }
      else
      {
        p = tail;
        while (p->prev != tail)
        {
          printf("%d ", p->data);
          p = p->prev;
        }
        printf("%d ", p->data);
      }
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