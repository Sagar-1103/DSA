#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

void DLLByNext(struct Node *head){
    struct Node *ptr = head;
    while (ptr)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void DLLByPrevious(struct Node *head){
    struct Node *ptr = head;
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    while (ptr)
    {
        printf("%d ",ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data=11;
    second->data=22;
    third->data=33;
    fourth->data=44;

    head->prev = NULL;
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = NULL;

    DLLByNext(head);
    DLLByPrevious(head);
    return 0;
}
