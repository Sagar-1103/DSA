#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
   struct Node *f = NULL;
   struct Node *r = NULL;
void traverse(struct Node *head){
    struct Node *ptr = head;
    while (ptr)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void enqueue(int value){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    if (n==NULL)
    {
        printf("Queue is full.\n");
    }
    else {
        n->data = value;
        n->next = NULL;
        if (f==NULL)
        {
            f=r=n;
        } else {
            r->next = n;
            r=n;
        }
        printf("%d has been enqueued.\n",value);
    }
    
}

void dequeue(){
    struct Node *ptr = f;
    if (f==NULL)
    {
        printf("Queue is empty");
    }
    else {
        f=f->next;
        printf("%d has been dequeued.\n",ptr->data);
        free(ptr);
    }
}

int main(int argc, char const *argv[])
{
    traverse(f);
    enqueue(6);
    enqueue(8);
    enqueue(4);
    enqueue(5);
    traverse(f);
    dequeue();
    traverse(f);
    return 0;
}
