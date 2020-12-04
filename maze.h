#ifndef __MAZE_H__
#define __MAZE_H__

int **createMaze(
    const char *file_name,
    int *size_x,
    int *size_y);
void destoryMaze(int **maze, int size_x);

#endif // __MAZE_H__
