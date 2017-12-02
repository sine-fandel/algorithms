/*
     深度优先遍历算法
         author：fang
 测试数据：
 0 1 1 1 0 0 0 0 0
 1 0 0 0 1 1 0 0 0
 1 0 0 0 0 0 1 1 0
 1 0 0 0 0 0 0 0 1
 0 1 0 0 0 0 0 0 0
 0 1 0 0 0 0 0 0 0
 0 0 1 0 0 0 0 0 0
 0 0 1 0 0 0 0 0 0
 0 0 0 1 0 0 0 0 0
 */

#include <iostream>
using namespace std;

int map[10][10];
int visited[10];

//dfs核心算法
void dfs (int i)
{
    cout << i << ' ';
    visited[i] = 1;
    for (int j = 1; j < 10; j++)
        if (visited[j] == 0 && map[i][j] == 1)
            dfs(j);
}

//dfs入口函数
void dfsmain ()
{
    for (int i = 1; i < 10; i++)
        if (visited[i] == 0)
            dfs(i);
}

int main ()
{
    for (int i = 1; i < 10; i++)
    {
        visited[i] = 0;
    }
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cin >> map[i][j];
        }
    }
    dfsmain();
    return 0;
}
