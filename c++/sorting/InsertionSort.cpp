#include <bits/stdc++.h>
using namespace std;
void SelectionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (a[j] > temp)
            {
                a[j + 1] = a[j];
            }
            else
                break;
        }
        a[j + 1] = temp;
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
    SelectionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}