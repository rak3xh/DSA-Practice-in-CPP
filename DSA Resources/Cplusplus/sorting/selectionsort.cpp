#include <iostream>
#include <algorithm>
using namespace std;
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                minIndex = j;
            }
            swap(a[i], a[minIndex]);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int a[20];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    selectionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}