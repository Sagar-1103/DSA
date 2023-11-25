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

struct Node* insertEnd(struct Node *head,int value)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *pointer = (struct Node *)malloc(sizeof(struct Node));
    pointer = head;
    ptr->data = value;
    while(pointer->next){
        pointer=pointer->next;
    }
    ptr->next = pointer->next;
    pointer->next = ptr;
    return head;
};


int main(int argc, char const *argv[])
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 11;
    second->data = 22;
    third->data = 33;
    fourth->data = 44;
    fifth->data = 55;
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    LLTraversal(head);
    head = insertEnd(head,66);
    LLTraversal(head);
    return 0;
}
