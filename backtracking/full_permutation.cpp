/*
    求全排列
 author:fang
*/

#include <iostream>
using namespace std;

char a[100];     //排列数组
int cou = 0;    //记录全排列个数
int total;      //元素个数

//交换函数
void swap (char *a, char *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//回溯求全排列
void backtracking (int n)
{
    if (n == total)
    {
        for (int i = 0; i < total; i++)
            cout << a[i];
        cout << endl;
        cou ++;
    }
    else
    {
        for (int j = n; j < total; j++)
        {
            swap (&a[n], &a[j]);
            backtracking (n + 1);
            swap (&a[n], &a[j]);
        }
    }
}

int main ()
{
    cout << "请输入元素个数：";
    cin >> total;
    for (int i = 0; i < total; i++)
        cin >> a[i];
    backtracking (0);
    cout << "全排列个数为：" << cou << endl;
}
