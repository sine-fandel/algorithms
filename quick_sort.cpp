#include <iostream>
using namespace std;

int quick (int a[], int left, int right)
{
    int i = left;
    int j = right;
    int temp = a[i];
    while (i < j)
    {
        while (a[j] > temp)
            j--;
        if (i < j)
        {
            a[i] = a[j];
            i++;
        }
        while (a[i] < temp)
            i++;
        if (i < j)
        {
            a[j] = a[i];
            j--;
        }
    }
    a[i] = temp;
    return i;
}

void quick_sort (int a[], int left, int right)
{
    if (left < right)
    {
        int j = quick (a, left, right);
        quick_sort (a, left, j - 1);
        quick_sort (a, j + 1, right);
    }
}

int main ()
{
    int a[] = {3, 5, 3, 6, 7, 3, 7, 8, 1};
    quick_sort (a, 0, 8);
    for (int i = 0; i < 9; i++)
        cout << a[i] << ' ';
}
