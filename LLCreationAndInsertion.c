#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LLTraversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void LLReverseTraversal(struct Node *head)
{
    if (head)
    {
        LLReverseTraversal(head->next);
        printf("%d ",head->data);
    }
}

int main(int argc, char const *argv[])
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 11;
    second->data = 22;
    third->data = 33;
    head->next = second;
    second->next = third;
    third->next = NULL;

    LLTraversal(head);
    LLReverseTraversal(head);
    return 0;
}
