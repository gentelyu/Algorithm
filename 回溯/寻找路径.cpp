#include <iostream>
#include <string.h>

/* 题目： 求一个矩形中是否包含一条路径 */


bool hasPathCore(const char *matrix, int row, int col, int rows, int cols, const char *str, bool *visited, int& pathLen)
{
    if (str[pathLen] == '\0')
        return true;

    bool hasPath = false;
    if (row >= 0 && row <= rows && col >= 0 && col <= cols && matrix[row * cols + col] == str[pathLen] && !visited[row *cols + col])
    {
        pathLen++;
        visited[row * cols + col] = true;

        hasPath = hasPathCore(matrix, row, col + 1, rows, cols, str, visited, pathLen)
                || hasPathCore(matrix, row, col - 1, rows, cols, str, visited, pathLen)
                || hasPathCore(matrix, row + 1, col, rows, cols, str, visited, pathLen)
                || hasPathCore(matrix, row -1, col, rows, cols, str, visited, pathLen);

        if (!hasPath)
        {
            pathLen--;
            visited[row * cols + col] = false;
        }
    }

    return hasPath;
}


bool isExitPath(char *matrix, int rows, int cols, const char *str)
{
    if (matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
        return false;

    bool *visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);

    int PathLen = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (hasPathCore(matrix, row, col, rows, cols, str, visited, PathLen))
            {
                return true;
            }
        }
    }

    delete[] visited;

    return false;
}

int main()
{
    char matrix[4][4] = {{'a', 'b', 'c', 'd'}, {'e', 'f', 'g','h'}, {'i', 'j', 'k', 'l'}, {'m', 'n', 'o', 'p'}};
    /* 不包含 */
    const char *str = "bfko";
    /* 包含 */
    const char *str1 = "bfgk";

    if (isExitPath((char *)matrix, 4, 4, str1))
    {
        printf("包含%s路径\n", str1);
    }
    else
    {
        printf("不包含%s路径\n", str1);
    }


    return 0;
}