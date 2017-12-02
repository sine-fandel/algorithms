/*
     归并排序
 author：fangrm
*/

#include <iostream>
using namespace std;

//归并排序
void merge (int a[], int start, int mid, int end, int sorted[])
{
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
            sorted[k++] = a[i++];
        else
            sorted[k++] = a[j++];
    }
    while (i <= mid)
        sorted[k++] = a[i++];
    while (j <= end)
        sorted[k++] = a[j++];
    for (int s = 0; s < k; s++)
        a[start + s] = sorted[s];
}

//将数组分成最小的部分
void merge_sort (int a[], int start, int end, int sorted[])
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort (a, start, mid, sorted);
        merge_sort (a, mid + 1, end, sorted);
        merge (a, start, mid, end, sorted);
    }
}

int main ()
{
    int a[] = {3, 5, 3, 6, 7, 3, 7, 8, 1};
    int sorted[9];
    //sorted = new int [9];
    merge_sort (a, 0, 8, sorted);
    for (int i = 0; i < 9; i++)
        cout << a[i] << ' ';
    
}
