#include <bits/stdc++.h>
using namespace std;
void Insert(int a[], int i)
{

    int temp = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > temp)
    {
        a[j + 1] = a[j];
        j--;
    }
    a[j + 1] = temp;
}

void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Insert(a, i);
    }
}
int main()
{
    int n, a[20];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    InsertionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}