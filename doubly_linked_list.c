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
  struct node *p, *q, *head, *pre_node, *next_node, *current_node, *tail;

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
  p = head;
  while (p != NULL)
  {
    printf("%d ", p->data);
    tail = p;
    p = p->next;
  }
  while (1)
  {
    printf("\n1.Insert the element at beginning\n2.Insert the element at middle\n3.Insert the element at end\n4.Delete the element at beginning\n5.Delete the element at middle\n6.Delete the element at end\n7.print all elements\n8.print elements at reverse order using prev\n9.count\n10.display the reversed list\n11.save the reverse list\n12.escape\nEnter the choice:");
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
      head = q;
      printf("The head element is %d\n", head->data);
      p = head;
      while (p != NULL)
      {
        printf("%d ", p->data);
        p = p->next;
      }
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
      while (p != NULL)
      {
        count = count + 1;
        p = p->next;
      }
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
        while (p != NULL)
        {
          printf("%d ", p->data);
          p = p->next;
        }
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
      q->prev = NULL;
      tail->next = q;
      q->prev = tail;
      tail = tail->next;
      p = head;
      while (p != NULL)
      {
        printf("%d ", p->data);
        p = p->next;
      }
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
        head = NULL;
        free(p);
      }
      else
      {
        head = head->next;
        head->prev = NULL;
        free(p);
        p = head;
        if (head == 0)
        {
          printf("The last element in the list also has been deleted");
        }
        else
        {
          while (p != NULL)
          {
            printf("%d ", p->data);
            p = p->next;
          }
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
        while (p != NULL)
        {
          count++;
          p = p->next;
        }
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
          next_node->prev = NULL;
          pre_node->next = NULL;
          p->next = NULL;
          p->prev = NULL;
          free(p);
          pre_node->next = next_node;
          next_node->prev = pre_node;
          p = head;
          while (p != NULL)
          {
            printf("%d ", p->data);
            p = p->next;
          }
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
      else
      {
        tail = tail->prev;
        tail->next = NULL;
        free(p);
        p = head;
        if (head == 0)
        {
          printf("The list is empty");
        }
        else
        {
          while (p != NULL)
          {
            printf("%d ", p->data);
            p = p->next;
          }
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
        while (p != tail)
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
        while (p != NULL)
        {
          printf("%d ", p->data);
          p = p->prev;
        }
      }
    }

    else if (choice == 9)
    {
      p = head;
      if (p == 0)
      {
        printf("There is no element present");
      }
      else
      {
        while (p != NULL)
        {
          count++;
          p = p->next;
        }
        printf("The count is %d", count);
        count = 0;
      }
    }
    else if (choice == 10)
    {
      next_node = current_node = head;
      if (head == NULL)
      {
        printf("There is no element present");
      }
      else
      {
        while (current_node != NULL)
        {
          next_node = current_node->next;
          current_node->next = current_node->prev;
          current_node->prev = next_node;
          current_node = next_node;
        }
        current_node = head;
        head = tail;
        tail = current_node;
        p = head;
        while (p != tail)
        {
          printf("%d ", p->data);
          p = p->next;
        }
        printf("%d ", p->data);
        next_node = current_node = head;
        while (current_node != NULL)
        {
          next_node = current_node->next;
          current_node->next = current_node->prev;
          current_node->prev = next_node;
          current_node = next_node;
        }
        current_node = head;
        head = tail;
        tail = current_node;
      }
    }
    else if (choice == 11)
    {
      next_node = current_node = head;
      if (head == NULL)
      {
        printf("There is no element present");
      }
      else
      {
        while (current_node != NULL)
        {
          next_node = current_node->next;
          current_node->next = current_node->prev;
          current_node->prev = next_node;
          current_node = next_node;
        }
        current_node = head;
        head = tail;
        tail = current_node;
        p = head;
        while (p != tail)
        {
          printf("%d ", p->data);
          p = p->next;
        }
        printf("%d ", p->data);
      }
    }
    else if (choice == 12)
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