#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>

#define MAX_SIZE 1000

struct point {
    int x;
    int y;
};

typedef struct point Point;
typedef struct point *pPoint;

struct queue {
    int front;
    int rear;
    int size;
    unsigned capacity;
    pPoint array;
};

typedef struct queue Queue;
typedef struct queue *pQueue;

pQueue createQueue(unsigned capacity);
bool isEmpty(pQueue queue);
bool isFull(pQueue queue);
void enQueue(pQueue queue, pPoint data);
Point deQueue(pQueue queue);
Point peek(pQueue queue);
int getSize(pQueue queue);

#endif // !__QUEUE_H__