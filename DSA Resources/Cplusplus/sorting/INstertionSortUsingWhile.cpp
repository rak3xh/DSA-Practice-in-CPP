#include <bits/stdc++.h>
using namespace std;
void InstertionSort(int a[], int n)
{
    int i = 1;
    while (i < n)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (a[j] > temp)
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
            j--;
        }
        a[j + 1] = temp;
        i++;
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
    InstertionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}