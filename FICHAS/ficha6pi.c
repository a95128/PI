#include <stdio.h>
#include <stdlib.h>
#define Max 10

struct staticStack {
    int sp;
    int values[Max];
};

typedef struct staticStack *SStack, STACK;

void SinitStack(SStack s) {
    s->sp = 0; 
}

int SisEmpty (SStack s) {
    return s->sp == 0;
}

int Spush(SStack s, int x) {
    if(s->sp < Max) {
        s->values[s->sp] = x;
        s->sp++;
        return 0;
    }
    else return 1;
}

int Spop(SStack s, int *x) {
    if (SisEmpty(s)) 
        return 1;
    else {
        *x = s->values[s->sp-1];
        s->sp--;
        return 0;
    }
}

int Stop(SStack s, int *x) {
    if (SisEmpty(s)) 
        return 1;
    else {
        *x = s->values[s->sp-1];
        return 0;
    }

}

struct staticQueue {
    int front;
    int length;
    int values[Max];
};

typedef struct staticQueue *SQueue, Queue;

void SinitQueue(SQueue q) {
    q->length = 0;
    q->front = 0;
}

int SisEmptyQ(SQueue q) {
    return q->length == 0;
}

int Senqueue(SQueue q, int x) {
    if(q->length < Max) {
        q->length++;
        q->values[q->front+q->length-1] = x;
        return 0;
    }
    else {
        return 1;
    }
}

int Sdequeue(SQueue q, int *x) {
    if(q->length == 0) {
        return 1;
    }
    else {
        *x = q->values[q->front];
        q->front++;
        q->length--;
        return 0;
    }
}

int Sfront(SQueue q, int *x)  {
    if(q->length == 0) {
        return 1;
    }
    else {
        *x = q->values[q->front];
        return 0;
    }

}

typedef struct dinStack {
    int size; 
    int sp;
    int *values;
} *DStack;

typedef struct dinQueue {
    int size;
    int front;
    int length;
    int *values;
} *DQueue;


int Spush(DStack s, int x) {
    if(s->sp < s->size) {
        s->values[s->sp++] = x; 
        return 1; 
    } else {
        int new_size = s->size * 2; 
        int *new_values = realloc(s->values, sizeof(int) * new_size); 

        if (new_values == NULL) { 
            return 0; 
        } else {
            s->values = new_values; 
            s->size = new_size; 
            s->values[s->sp++] = x; 
            return 1; 
        }
    }
}

int Spop(DStack s, int *x) {
    if (s->sp > 0) { 
        *x = s->values[--(s->sp)]; 
        return 1; 
    } else {
        return 0; 
}
}



int main() {
    struct staticStack stack;
    SStack s = &stack;

    SinitStack(s); 
    Spush(s, 10);
    

    //printf("%d\n", SisEmpty(s));
    //printf("%d\n", Spush(s,10));
    //Spop(s, &s->values[s->sp]);
    //printf("%d\n", SisEmpty(s));

    struct staticQueue queue;
    SQueue q = &queue;

    SinitQueue(q);
    Senqueue(q, 10);
    Senqueue(q, 20);
    Senqueue(q, 30);
    printf("%d\n", SisEmptyQ(q));
    printf("%d\n", Senqueue(q, 40));
    printf("%d\n", Sdequeue(q, &q->values[q->front]));
    printf("%d\n", q->values[q->front]);

    return 0;
}
