#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "queue.h"

pQueue createQueue(unsigned capacity)
{
    assert(capacity > 0 && capacity <= MAX_SIZE);
    pQueue queue = (pQueue)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (pPoint)malloc(
        sizeof(Point) * capacity);
    return queue;
}

bool isEmpty(pQueue queue)
{
    assert(queue != NULL);
    return (queue->size == 0);
}

bool isFull(pQueue queue)
{
    assert(queue != NULL);
    return (queue->size == queue->capacity);
}

void enQueue(pQueue queue, pPoint data)
{
    assert(queue != NULL);
    assert(!isFull(queue));
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = *data;
    queue->size = queue->size + 1;
}

Point deQueue(pQueue queue)
{
    assert(queue != NULL);
    assert(!isEmpty(queue));
    Point data = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return data;
}

Point peek(pQueue queue)
{
    assert(queue != NULL);
    return queue->array[queue->front];
}

int getSize(pQueue queue)
{
    assert(queue != NULL);
    return queue->size;
}