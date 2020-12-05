#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "maze.h"

// #define DEBUG

Maze createMaze(
    const char *file_name,
    int *size_x,
    int *size_y)
{
    FILE *pFile;
    pFile = fopen(file_name, "r");

    int m, n;
    
    fscanf(pFile, "%d %d", &m, &n);

    assert(m >= 1 && m <= 100);
    assert(n >= 1 && n <= 100);

    *size_x = m;
    *size_y = n;

    Maze maze = NULL;
    maze = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++) {
        maze[i] = (int *)malloc(sizeof(int) * n);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(pFile, "%d", &(maze[i][j]));
        }
    }

#ifdef DEBUG

printf("=== DEBUG OUTPUT START ===\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
printf("===  DEBUG OUTPUT END  ===\n");

#endif // DEBUG

    fclose(pFile);

    return maze;
}

void destoryMaze(Maze maze, int size_x)
{
    for (int i = 0; i < size_x; i++) {
        free(maze[i]);
    }
    free(maze);
}

void printMaze(Maze maze, int size_x, int size_y)
{
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}
