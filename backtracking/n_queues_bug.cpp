/*
    n皇后问题
 author: fang
*/
#include <iostream>
using namespace std;

int c = 0;  //计数
int m[8][8];   //棋盘
int t;  //皇后个数



//判断位置是否可行
bool isValue (int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        //if (row == 7 && col == 3) cout << m[i][col] << m[i][col - (row - i)] << m[i][col + (row - i)] << ' ';
        if (m[i][col] == 1)     //该列是否有其他皇后
            return false;
        if (col - (row - i) > 0 && m[i][col - (row - i)] == 1)
            return false;
        if (col + (row - i) < t && m[i][col + (row - i)] == 1)
            return false;

        
    }
    return true;
}


//回溯
void backtracking (int n)
{
    if (n == t)     //已放好t个皇后
    {
        c ++;
    }
    else
    {
        for (int i = 0; i < t; i++)
        {

            if (isValue(n, i))    //当前位置可行
            {
                
                m[n][i] = 1;
                backtracking (n + 1);
                m[n][i] = 0;
            }
        }
    }
}

int main ()
{
    cout << "请输入皇后个数：";
    cin >> t;
    backtracking (0);
    cout << "方案共有：" << c << "种" << endl;
    //bool test = isValue (7, 3);
}
