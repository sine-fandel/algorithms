/*
	广度优先遍历算法
		author:fang
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
#include <queue>
using namespace std;

int map[10][10];
int visited[10];

/*
 bfs核心算法
 参数：
 t：点的总数
 */
void bfs (int t)
{
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int i = q.front();
        if (visited[i] == 0)
        {
            cout << i << ' ';
            visited[i] = 1;
            q.pop();
            for (int j = 1; j < t; j++)
            {
                if (map[i][j] != 0 && visited[j] == 0)
                    q.push(j);
            }
        }
    }
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
    bfs(10);
    return 0;
}











