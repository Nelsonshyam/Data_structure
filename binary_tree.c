#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    struct node *newnode;
    int item;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element(note:giving -1 you can get back one node):");
    scanf("%d", &item);
    if (item == -1)
    {
        return NULL;
    }
    newnode->data = item;
    printf("Enter the left child:");
    newnode->left = create();
    printf("Enter the right child:");
    newnode->right = create();
    return newnode;
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

int main()
{
    struct node *root = NULL;
    int choice;
    while (1)
    {
        printf("\nChoice the options:\n1.Create a Binary tree\n2.preorder\n3.post order\n4.Inorder\n5.escape\nEnter the choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            root = create();
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
            break;
        }
        else
        {
            printf("You were entered the wrong option, please enter the correct option\n");
        }
    }
    return 0;
}