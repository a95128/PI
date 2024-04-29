#include <stdio.h>
#include <stdlib.h>
#define Max 10

typedef struct staticQueue { 
    int front;
    int length;
    int values[Max];
} QUEUE, *SQueue;

void SinitQueue(SQueue q) {
    q->length = 0;
    q->front=0;
    for(int i=0; i<Max; i++) q->values[i]=0;
}

int SisEmptyQ(SQueue q) {
    if (q->length == 0) return 1;
}

int Senqueue(SQueue q, int x) {
    if(q->length == Max) return 1;
    q->values[(q->front + q->length) % Max] = x;
    q->length++;
}

int Sfront(SQueue q, int *x) {
    if(q->length == 0) return 1;
    else {
        *x = (q->values[q->front]);
        return 0;
    }
}

int main() {
    SQueue q = (SQueue) malloc(sizeof(QUEUE));
    SinitQueue(q);
    int x;
    if(SisEmptyQ(q)) printf("Queue is empty\n");
    if(Senqueue(q, 10)) printf("Queue is full\n");
    if(Sfront(q, &x)) printf("Queue is empty\n");
    printf("Front: %d\n", x);
    return 0;
}