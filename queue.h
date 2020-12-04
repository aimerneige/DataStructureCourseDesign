#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>

#define MAX_SIZE 100

struct queue
{
    int front;
    int rear;
    int size;
    unsigned capacity;
    int *array;
};

typedef struct queue Queue;
typedef struct queue *pQueue;

pQueue createQueue(unsigned capacity);
bool isEmpty(pQueue queue);
bool isFull(pQueue queue);
void enQueue(pQueue queue, int data);
int deQueue(pQueue queue);
int peek(pQueue queue);
int getSize(pQueue queue);

#endif // !__QUEUE_H__