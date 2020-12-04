#include <stdio.h>
#include <stdlib.h>

#include "maze.h"

int main(int argc, char const *argv[])
{
    printf("Hello World!\n");

    int m, n;
    int **maze = createMaze("maze.txt", &m, &n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    destoryMaze(maze, n);

    return 0;
}