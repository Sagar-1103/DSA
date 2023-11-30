#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct Node *search(struct Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == value)
    {

        return root;
    }
    else if (root->data > value)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}

struct Node *iterativeSearch(struct Node *root, int value)
{
    while (1)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == value)
        {
            return root;
        }
        else if (root->data > value)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
}

struct Node *insert(struct Node *root, int value)
{
    struct Node* pointer = root;
    struct Node* p;
    struct Node* ptr = createNode(value);
    while (1)
    {
        if (pointer==NULL)
        {
            break;
        }
        if (pointer->data > value)
        {
            p=pointer;
            pointer = pointer->left;
        }
        else
        {
            p=pointer;
            pointer = pointer->right;
        }
    }
    if (p->data>value)
    {
        p->left=ptr;
    }
    else {
        p->right=ptr;
    }
    return root;
}

int main(int argc, char const *argv[])
{
    struct Node *root = createNode(23);
    struct Node *p1 = createNode(4);
    struct Node *p2 = createNode(5);
    struct Node *p3 = createNode(9);
    struct Node *p4 = createNode(1);
    struct Node *p5 = createNode(6);

    root->left = p1;
    p1->left = p4;
    p1->right = p2;
    p2->right = p3;
    p3->left = p5;

    inorder(root);
    printf("\n");
    if (isBST(root))
    {
        printf("It is a binary search tree.\n");
    }
    else
    {
        printf("It is not a binary search tree.\n");
    }

    // root = search(root,5);
    // inorder(root);
    // root = iterativeSearch(root,5);
    // inorder(root);
    root = insert(root, 24);
    inorder(root);
    return 0;
}
