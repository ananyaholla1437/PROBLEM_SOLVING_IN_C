#include <stdio.h>

// Rat in a maze

#define N 4

int findingPath(int maze[N][N], int x, int y, char path[], int index)
{
    // Base case
    if (x == N - 1 && y == N - 1)
    {
        path[index] = '\0';
        printf("%s\n", path);
        return 1;
    }

    // Check invalid position
    if (x >= N || y >= N || maze[x][y] == 0)
    {
        return 0;
    }

    // Down
    path[index] = 'D';

    if (findingPath(maze, x + 1, y, path, index + 1))
    {
        return 1;
    }

    // Right
    path[index] = 'R';

    if (findingPath(maze, x, y + 1, path, index + 1))
    {
        return 1;
    }

    return 0;
}

int main()
{
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    char path[100];

    findingPath(maze, 0, 0, path, 0);

    return 0;
}