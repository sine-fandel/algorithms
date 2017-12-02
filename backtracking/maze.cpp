/*
    迷宫问题
  author：fangrm
*/

#include <iostream>
#include <stack>
using namespace std;

int top = -1;   //-1表示还没开始走

//迷宫数组，0:可行 1:不可行
int maze[5][5]={
    {0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 1, 0, 0},
    {0, 1, 1, 0, 1},
    {0, 0, 0, 0, 0}
};

//储存迷宫位置的结构体
struct place
{
    int col;  //位置的列坐标
    int row;  //位置的行坐标
}p[100];    

//回溯法求路径 (xi, yi)表示当前位置 (xe, ye)表示目标位置
void backtracking (int xi, int yi, int xe, int ye)
{
    if (xe == xi && ye == yi)     //若到达目的地则输出路径
    {
        cout << "迷宫路径如下：" << endl;
        for (int i = 0; i <= top; i++)
          cout << "(" << p[i].col << ", " << p[i].row << ") -> ";
        cout << endl;
        return;
    }
    else
    {
        int x, y;
        top += 1;
        p[top].col = xi;
        p[top].row = yi;
        for (int i = 0; i < 4; i++)   //搜索这位置的可行路径
        {
            switch (i)
            {
                case 0 :  x = xi + 1;   y = yi;   break;
                case 1 :  x = xi;   y = yi + 1;   break;
                case 2 :  x = xi - 1;   y = yi;   break;
                case 3 :  x = xi;   y = yi - 1;   break;
            }
            if (x >= 0 && y >= 0 && maze [y][x] == 0)   //若为通路
            {
                backtracking (x, y, xe, ye);
                top -= 1;
            }
        }
    }
}

int main ()
{
    cout << "请输入目的地：";
    int xe, ye;
    cin >> xe >> ye;    
    backtracking (0, 0, 4, 4);
}
