#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        swap(a[minIndex], a[i]);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[50];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    SelectionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
