#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct Queue *q){
    if (q->r==q->size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct Queue *q){
    if (q->r==q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct Queue *q,int value){
    if (isFull(q))
    {
        printf("Queue is full!");
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;
        printf("%d has been enqueued.\n",value);
    } 
}
int dequeue(struct Queue *q){
    int a=-1;
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
    }
    else {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
    
}

int main(int argc, char const *argv[])
{
    struct Queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));
    dequeue(&q);
    enqueue(&q,2); 
    enqueue(&q,4);
    enqueue(&q,3);
    printf("Dequeued element %d\n",dequeue(&q));
    printf("Dequeued element %d\n",dequeue(&q));
    return 0;
}
