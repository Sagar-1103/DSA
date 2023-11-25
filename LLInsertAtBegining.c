#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};


void LLTraversal(struct Node *head)
{
    if (head)
    {
        printf("%d ",head->data);
        LLTraversal(head->next);
    }
}

struct Node* insertAtBeginning(struct Node *head,int value){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=value;
    ptr->next = head;
    head=ptr;
    return head;
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
    printf("\n");
    struct Node *head1 = (struct Node *)malloc(sizeof(struct Node));
    head1=insertAtBeginning(head,6);
    LLTraversal(head1);
    return 0;
}
