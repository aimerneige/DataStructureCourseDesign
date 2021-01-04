#include <stdio.h>

// 箭头
char sign[] = {'-', 'u', 'd', 'l', 'r'};

int m; // 行号
int n; // 列号
int maze[200][200]; // 存储迷宫数据

struct stack {
    int x; // 当前位置的行号
    int y; // 当前位置的列号
    int d; // 下一方向的方位号 1上 2下 3左 4右 0空
};

struct stack st[10000]; // 存储节点的栈
struct stack min[10000]; // 存储最短节点
int min_len = -1; // 最短路径长度
int top = -1; // 栈指针

void stackSave()
{
    for (int i = 0; i <= top; i++) {
        min[i].x = st[i].x;
        min[i].y = st[i].y;
        min[i].d = st[i].d;
    }
}

// 深度优先算法
int DFS(int x_start, int y_start, int x_end, int y_end)
{
    int solved = 0;
    // 初始方块入栈
    top++;
    st[top].x = x_start;
    st[top].y = y_start;
    st[top].d = 0;
    maze[x_start][y_start] = -1;
    while (top > -1) // 栈不为空时循环
    {
        int x = st[top].x;
        int y = st[top].y;
        int d = st[top].d;
        if ((x == x_end) && (y == y_end)) // 找到了出口，输出路径
        {
            if (solved == 0) {
                solved = 1;
                min_len = top;
                stackSave();
            }
            else {
                if (top < min_len) {
                    min_len = top;
                    stackSave();
                }
            }
            printf("找到了一条通路，路径如下：\n");
            // 输出路径
            for (int k = 0; k <= top; k++) {
                printf("(%d, %d, %c) ", st[k].x, st[k].y, sign[st[k].d]);
            }
            printf("\n");
        }
        int find = 0; // 用于保存是否找到
        while (d < 4 && find == 0)
        {
            d++;
            switch (d)
            {
            case 1:
                x = st[top].x - 1;
                y = st[top].y;
                break;
            case 2:
                x = st[top].x + 1;
                y = st[top].y;
                break;
            case 3:
                x = st[top].x;
                y = st[top].y - 1;
                break;
            case 4:
                x = st[top].x;
                y = st[top].y + 1;
                break;
            default:
                break;
            }
            if (maze[x][y] == 0) {
                find = 1;
            }
        }
        if (find) // 有路可走，保存信息并入栈
        {
            st[top].d = d;
            top++;
            st[top].x = x;
            st[top].y = y;
            st[top].d = 0;
            maze[x][y] = -1; // 避免重复走到这个方块
        }
        else // 无路可走，退栈
        {
            maze[st[top].x][st[top].y] = 0; // 恢复为可走状态
            top--;
        }
    }
    return solved;
}

int main()
{
    // 读取文件
    FILE *pFile = fopen("maze.txt", "r");
    // 读取行列数
    fscanf(pFile, "%d %d", &m, &n);
    // 读取地图数据
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(pFile, "%d", &(maze[i][j]));
        }
    }
    // 输出迷宫
    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    // 尝试找到通路
    if (!DFS(1, 1, m - 2, n - 2)) {
        printf("无解\n");
    }
    else {
        printf("最短通路：\n");
        for (int k = 0; k <= min_len; k++) {
            printf("(%d, %d, %c) ", min[k].x, min[k].y, sign[min[k].d]);
        }
        printf("\n");
    }
    
    return 0;
}
