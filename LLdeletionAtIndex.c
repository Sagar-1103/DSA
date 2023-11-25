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

struct Node *deleteFromEnd(struct Node *head,int index){
    struct Node *p = head;
    int i =0;
    while(i!=index-1 && p->next!=NULL){
        p=p->next;
        i++;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

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
    head = deleteFromEnd(head,3);
    LLTraversal(head);
    return 0;
}
