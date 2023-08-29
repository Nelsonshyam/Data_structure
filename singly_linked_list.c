#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

int create_head(struct node **head)
{
  int item;
  struct node *q;
  q = (struct node *)malloc(sizeof(struct node));
  printf("Enter the head element:");
  scanf("%d", &item);

  q->data = item;
  q->next = NULL;
  *head = q;
}

int create_node(struct node **head)
{
  int i, item;
  struct node *p, *q;
  p = *head;
  if (p == 0)
  {
    printf("Head is not present, Please enter head element\n");
    create_head(head);
  }
  else
  {
    p = *head;
    while (p->next != NULL)
    {
      p = p->next;
    }
    q = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element:");
    scanf("%d", &item);

    q->data = item;
    q->next = NULL;
    p->next = q;
    p = p->next;
    p = *head;
    while (p != NULL)
    {
      printf("%d ", p->data);
      p = p->next;
    }
  }
}

int insert_begin(struct node **head)
{
  int item;
  struct node *p, *q;
  p = *head;
  q = (struct node *)malloc(sizeof(struct node));
  printf("Enter the new head element:");
  scanf("%d", &item);

  q->data = item;
  q->next = NULL;
  q->next = p;
  *head = q;

  p = *head;
  printf("The head element is %d\n", p->data);
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
}

int insert_middle(struct node **head)
{
  int item, count, position, i;
  struct node *p, *q, *pre_node, *next_node;

  printf("Enter the position where you want to insert the element:");
  scanf("%d", &position);

  printf("Enter the element which you want to insert:");
  scanf("%d", &item);
  q = (struct node *)malloc(sizeof(struct node));
  q->data = item;
  q->next = NULL;

  count = 0;
  p = *head;
  while (p != NULL)
  {
    count = count + 1;
    p = p->next;
  }
  printf("The count is %d\n", count);
  p = *head;
  if (count < position)
  {
    printf("Invalid position");
  }
  else if (count == 1)
  {
    q->next = p;
    *head = q;
  }
  else
  {
    i = 0;
    while (i < position - 1)
    {
      pre_node = p;
      p = p->next;
      i++;
    }
    pre_node->next = q;
    q->next = p;
    p = *head;
    while (p != NULL)
    {
      printf("%d ", p->data);
      p = p->next;
    }
  }
}
int insert_aft_position(struct node **head)
{
  int item, count, position, i;
  struct node *p, *q, *pre_node, *next_node;

  printf("Enter the position where you want to insert the element:");
  scanf("%d", &position);

  printf("Enter the element which you want to insert:");
  scanf("%d", &item);
  q = (struct node *)malloc(sizeof(struct node));
  q->data = item;
  q->next = NULL;

  count = 0;
  p = *head;
  while (p != NULL)
  {
    count = count + 1;
    p = p->next;
  }
  printf("The count is %d\n", count);
  p = *head;
  if (count < position)
  {
    printf("Invalid position");
  }
  else if (count == 1)
  {
    p->next = q;
    *head = p;
  }
  else
  {
    i = 0;
    while (i < position - 1)
    {
      pre_node = p;
      p = p->next;
      i++;
    }
    p = p->next;
    pre_node = pre_node->next;
    pre_node->next = q;
    q->next = p;
    p = *head;
    while (p != NULL)
    {
      printf("%d ", p->data);
      p = p->next;
    }
  }
}

int insert_end(struct node **head)
{
  int item;
  struct node *p, *q;
  p = *head;
  if (p == NULL)
  {
    printf("There is no head element, please ");
    create_head(head);
  }
  else
  {
    while (p->next != NULL)
    {
      p = p->next;
    }
    q = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element which you want to insert at end:");
    scanf("%d", &item);
    q->data = item;
    q->next = NULL;
    p->next = q;
    p = *head;
    while (p != NULL)
    {
      printf("%d ", p->data);
      p = p->next;
    }
  }
}
int delete_begin(struct node **head)
{
  struct node *p, *next_node;
  p = *head;
  if (p == 0)
  {
    printf("The list is empty,Insert some elements");
  }
  else
  {
    next_node = p->next;
    *head = next_node;
    free(p);
    p = *head;
    if (p == 0)
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

int delete_middle(struct node **head)
{
  int position, count, i;
  struct node *p, *q, *pre_node, *next_node;
  p = *head;
  if (p == 0)
  {
    printf("The list is empty, Insert some elements");
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
      p = *head;
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
      p = *head;
      while (p != NULL)
      {
        printf("%d ", p->data);
        p = p->next;
      }
    }
  }
}

void delete_end(struct node **head)
{
  struct node *p, *pre_node;
  p = *head;
  if (p == NULL)
  {
    printf("The list is empty, Insert some elements");
  }
  if (p->next == NULL)
  {
    free(p);
    printf("The last element has been deleted");
  }
  else
  {
    while (p->next != NULL)
    {
      pre_node = p;
      p = p->next;
    }
    pre_node->next = NULL;
    free(p);
    p = *head;
    while (p != NULL)
    {
      printf("%d ", p->data);
      p = p->next;
    }
  }
}
int display(struct node **head)
{
  struct node *p;
  p = *head;
  if (p == 0)
  {
    printf("There is no element in the list");
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

void count(struct node **head)
{
  struct node *p;
  int count = 0;
  p = *head;
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

void display_reverse(struct node **head)
{
  struct node *current_node, *next_node, *pre_node, *p;
  next_node = current_node = *head;
  pre_node = NULL;
  if (current_node == 0)
  {
    printf("There is no element present");
  }
  else
  {
    while (current_node != NULL)
    {
      next_node = next_node->next;
      current_node->next = pre_node;
      pre_node = current_node;
      current_node = next_node;
    }
    *head = pre_node;
    p = *head;
    while (p != NULL)
    {
      printf("%d ", p->data);
      p = p->next;
    }
    next_node = current_node = *head;
    pre_node = NULL;
    while (current_node != NULL)
    {
      next_node = next_node->next;
      current_node->next = pre_node;
      pre_node = current_node;
      current_node = next_node;
    }
    *head = pre_node;
  }
}
void save_reverse(struct node **head)
{
  struct node *current_node, *next_node, *pre_node, *p;
  next_node = current_node = *head;
  pre_node = NULL;
  if (current_node == 0)
  {
    printf("There is no element present");
  }
  else
  {
    while (current_node != NULL)
    {
      next_node = next_node->next;
      current_node->next = pre_node;
      pre_node = current_node;
      current_node = next_node;
    }
    *head = pre_node;
    p = *head;
    while (p != NULL)
    {
      printf("%d ", p->data);
      p = p->next;
    }
  }
}

int main()
{
  struct node *head;
  int choice;
  create_head(&head);

  while (1)
  {
    printf("\n1.Insert the element\n2.Insert the element at beginning\n3.Insert the element at middle\n4.Insert after position\n5.Insert the element at end\n6.Delete the element at beginning\n7.Delete the element at middle\n8.Delete the element at end\n9.print all elements\n10.Count\n11.Display the reversed list\n12.save the reversed element\n13.escape\nEnter the choice:");
    scanf("%d", &choice);
    if (choice == 1)
    {
      create_node(&head);
    }
    if (choice == 2)
    {
      insert_begin(&head);
    }
    else if (choice == 3)
    {
      insert_middle(&head);
    }
    else if (choice == 4)
    {
      insert_aft_position(&head);
    }
    else if (choice == 5)
    {
      insert_end(&head);
    }
    else if (choice == 6)
    {
      delete_begin(&head);
    }
    else if (choice == 7)
    {
      delete_middle(&head);
    }
    else if (choice == 8)
    {
      delete_end(&head);
    }
    else if (choice == 9)
    {
      display(&head);
    }
    else if (choice == 10)
    {
      count(&head);
    }
    else if (choice == 11)
    {
      display_reverse(&head);
    }
    else if (choice == 12)
    {
      save_reverse(&head);
    }
    else if (choice == 13)
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