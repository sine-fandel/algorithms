/*戴克斯特拉算法
	author：fang
*/

#include <iostream>
#include <string.h>
using namespace std;

#define INF 99999999	//无限大

int map[500][500];	//图
int dis[500];	//距离数组
bool book[500];	//距离是否确定

/*戴克斯特拉算法
	参数：
		n：第n个点
		m：点的总数
		s：第s个点
	返回值：第n个点到第s个点的最短距离数组
*/
int Dijkstra (int n, int m, int s)
{
	dis[n] = 0;
	int f = 0;
	while (f < m && book[s] != true)
	{
		int min = INF;
		int u;
		//求离n最近的点
		for (int j = 1; j <= m; j++)
		{
			if (dis[j] < min && book[j] == false)
			{
				min = dis[j];
				u = j;
			}
		}
		book[u] = true; //点u已确定最短路径
		for (int k = 1; k <= m; k++)
		{
			if (map[u][k] < INF)
				if (dis[k] > dis[u] + map[u][k])
					dis[k] = dis[u] + map[u][k];
		}
		f++;
	}
	return dis[s];
}

int main ()
{
	memset(dis, 9999999, sizeof(dis));
	memset(book, false, sizeof(book));

    int a, b, l;	//ab两点及变长l
    int e, t;	//边数量 点数量
    cin >> e >> t;
    //初始化
    for(int i=1;i<=t;i++)
        for(int j=1;j<=t;j++)
            if(i==j) map[i][j]=0;
          		else map[i][j]=INF;
    for (int i = 0; i < e; i++)
    {
    	cin >> a >> b >> l;
    	map[a][b] = l;
    }

    int n, s;	//n到s的最短距离
    cin >> n >> s;
    int mindis = Dijkstra(n, t, s);
    printf("%d\n", mindis);
}
