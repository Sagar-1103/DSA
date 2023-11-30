#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct CircularQueue *q){
    if (((q->r+1)%q->size) == q->f)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct CircularQueue *q){
    if (q->r==q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct CircularQueue *q,int value){
    if (q->r==-1)
    {
        q->r=0;
    }
    if (isFull(q))
    {
        printf("Queue is full!");
    }
    else
    {
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = value;
        printf("%d has been enqueued.\n",value);
    } 
}
int dequeue(struct CircularQueue *q){
    if (q->f==-1)
    {
        q->f=0;
    }
    
    int a=-1;
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
    }
    else {
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
    
}

int main(int argc, char const *argv[])
{
    struct CircularQueue q;
    q.size = 3;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));
    enqueue(&q,2); 
    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);
    enqueue(&q,6);
    // dequeue(&q);
    printf("Dequeued element %d\n",dequeue(&q));
    printf("Dequeued element %d\n",dequeue(&q));
    dequeue(&q);
    // printf("Dequeued element %d\n",dequeue(&q));
    // dequeue(&q);
    return 0;
}
