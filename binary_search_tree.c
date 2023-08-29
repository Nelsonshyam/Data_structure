#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int item)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = item;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int item)
{

    if (root == NULL)
    {
        root = create(item);
        return root;
    }
    else if (item >= root->data)
    {
        root->right = insert(root->right, item);
    }
    else
    {
        root->left = insert(root->left, item);
    }
    return root;
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void search_element(struct node *root, int item)
{
    if (root == NULL)
    {
        printf("The element is not present\n");
        return;
    }

    if (item < root->data)
    {
        search_element(root->left, item);
    }
    else if (item > root->data)
    {
        search_element(root->right, item);
    }
    else
    {
        printf("The element is found\n");
    }
}

int main()
{
    struct node *root = NULL;
    int choice, item;
    while (1)
    {
        printf("\nChoices:\n1.Insert new node\n2.preorder traversal\n3.post order traversal\n4.Inorder traversal\n5.search the tree\n6.Escape\nEnter the choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter the element:");
            scanf("%d", &item);
            root = insert(root, item);
        }
        else if (choice == 2)
        {
            printf("preorder is ");
            preorder(root);
        }
        else if (choice == 3)
        {
            printf("post order is ");
            postorder(root);
        }
        else if (choice == 4)
        {
            printf("Inorder is ");
            inorder(root);
        }
        else if (choice == 5)
        {
            printf("Enter the search elemen:");
            scanf("%d", &item);
            search_element(root, item);
        }
        else if (choice == 6)
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