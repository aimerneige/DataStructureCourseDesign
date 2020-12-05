#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "maze.h"
#include "queue.h"

static bool
solveUtil(
    Maze maze, Maze visited,
    int size_x, int size_y,
    int x, int y,
    Maze sol);

bool
solve(
    Maze maze,
    int size_x, int size_y)
{
    assert(maze != NULL);

    if (maze[0][0] == 1 ||
        maze[size_x - 1][size_y - 1] == 1) {
        return false;
    }

    int **visited = NULL;
    visited = (int **)malloc(sizeof(int *) * size_x);
    for (int i = 0; i < size_x; i++) {
        visited[i] = (int *)malloc(sizeof(int) * size_y);
    }
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            visited[i][j] = 0;
        }
    }

    int **sol = NULL;
    sol = (int **)malloc(sizeof(int *) * size_x);
    for (int i = 0; i < size_x; i++) {
        sol[i] = (int *)malloc(sizeof(int) * size_y);
    }
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            visited[i][j] = 0;
        }
    }

    return solveUtil(
        maze, visited,
        size_x, size_y,
        0, 0,
        sol);
}

static bool
canGo(
    Maze maze,
    int size_x, int size_y,
    int x, int y)
{
    assert(size_x > x && x >= 0);
    assert(size_y > y && y >= 0);
    return (maze[x][y] == 0);
}

static bool
solveUtil(
    Maze maze, Maze visited,
    int size_x, int size_y,
    int x, int y,
    Maze sol)
{
    // if (x, y) out range return false
    // also in case of segmentation fault
    if (x < 0 || y < 0 || x >= size_x || y >= size_y) {
        return false;
    }

    // if (x, y) is goal return true 
    if (
        x == size_x - 1 &&
        y == size_y - 1 &&
        maze[x][y] == 0 ) {
        sol[x][y] = 1;
        return true;
    }

    // check if maze[x][y] is valid
    if (canGo(maze, size_x, size_y, x, y)) {

        // Mark (x, y) as solution path
        sol[x][y] = 1;

        // Mark (x, y) as visited
        visited[x][y] = 1;

        // check if there is a path (x + 1, y)
        if (
            visited[x + 1][y] != 1 &&
            solveUtil(
                maze, visited,
                size_x, size_y,
                x + 1, y,
                sol
            ) == true
        ) {
            return true;
        }

        // check if there is a path (x, y + 1)
        if (
            visited[x][y + 1] != 1 &&
            solveUtil(
                maze, visited,
                size_x, size_y,
                x, y + 1,
                sol
            ) == true
        ) {
            return true;
        }

        // check if there is a path (x - 1, y)
        if (
            visited[x - 1][y] != 1 &&
            solveUtil(
                maze, visited,
                size_x, size_y,
                x - 1, y,
                sol
            ) == true
        ) {
            return true;
        }

        // check if there is a path (x, y - 1)
        if (
            visited[x][y - 1] != 1 &&
            solveUtil(
                maze, visited,
                size_x, size_y,
                x, y - 1,
                sol
            ) == true
        ) {
            return true;
        }

        /*
         * if none of above work
         * unmark (x, y) as solution path
         * and return false
         */
        sol[x][y] = 0;
        return false;
    }

    return false;
}