#include <stdio.h>
#include <stdlib.h>

// #define TEST // comment this when test done

int main(int argc, char const *argv[])
{
// test for env
#ifdef TEST
printf("=== TEST OUTPUT START ===\n");
    printf("Hello World!\n");
printf("===  TEST OUTPUT END  ===\n");
#endif // TEST

// test for create maze
#ifdef TEST
#include "maze.h"
printf("=== TEST OUTPUT START ===\n");
    int m, n;
    int **maze = createMaze("maze.txt", &m, &n);
    printMaze(maze, m, n);
    destoryMaze(maze, n);
printf("===  TEST OUTPUT END  ===\n");
#endif // TEST

// test for queue
#ifdef TEST
#include "queue.h"
printf("=== TEST OUTPUT START ===\n");
    pQueue queue = createQueue(10);
    enQueue(queue, 10);
    enQueue(queue, 12);
    enQueue(queue, 14);
    enQueue(queue, 18);
    enQueue(queue, 31);
    printf("%d ", deQueue(queue));
    printf("%d ", deQueue(queue));
    printf("%d",  deQueue(queue));
    printf("\n");
printf("===  TEST OUTPUT END  ===\n");
#endif // TEST




    return 0;
}