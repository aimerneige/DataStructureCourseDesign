#ifndef __MAZE_H__
#define __MAZE_H__

typedef int **Maze;

Maze createMaze(
    const char *file_name,
    int *size_x,
    int *size_y);
void destoryMaze(
    Maze maze,
    int size_x);
void printMaze(
    Maze maze,
    int size_x,
    int size_y);

#endif // __MAZE_H__
