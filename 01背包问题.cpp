/*
    01背包问题
 author: fang
*/

#include <iostream>
using namespace std;

int t;          //物品个数
int w[100];     //物品重量
int v[100];     //物品价值
int tw = 0;     //背包重量
int bv = 0;     //背包价值
int c;          //背包承重
int best = 0;   //最佳方案的总价值

//回溯求最佳方案
void backtracking (int n)
{
    if (n < t)
    {
        for (int i = 1; i >= 0; i--)     //1表示放 0表示不放
        {
            if (i == 1 && tw + w[n] <= c)
            {
                tw += w[n];
                bv += v[n];
                if (best < bv)
                    best = bv;
            }
            backtracking (n + 1);
            if (i == 1)
            {
                tw -= w[n];
                bv -= v[n];
            }
        }
    }
}

int main ()
{
    cout << "请输入物品个数：";
    cin >> t;
    cout << "请输入物品重量：";
    for (int i = 0; i < t; i++)
        cin >> w[i];
    cout << "请输入物品价值：";
    for (int i = 0; i < t; i++)
        cin >> v[i];
    cout << "请输入背包承重：";
    cin >> c;
    backtracking(0);
    cout << "回溯法求得最佳方案的总价值为：" << best << endl;
}
