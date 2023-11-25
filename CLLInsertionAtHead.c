#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void CLLTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr!=head);
    
    printf("\n");
}

struct Node* insertAtHead(struct Node *head,int value){
struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
struct Node *p = head;
ptr->data=value;

p=p->next;
while (p->next!=head)
{
    p=p->next;
}


ptr->next = p->next;
p->next = ptr;

return ptr;
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
    third->next = head;

    CLLTraversal(head);
    head = insertAtHead(head,6);
    CLLTraversal(head);
    return 0;
}
