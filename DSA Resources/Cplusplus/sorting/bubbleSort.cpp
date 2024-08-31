#include <iostream>
#include <algorithm>
using namespace std;
void BubbleSort(int a[], int n)
{
    // for (int i = 0; i < n - 1; i++)
    // for (int j = 0; j < n - i - 1; j++)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j + 1] < a[j])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
int main()
{
    int n;
    int a[20];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    BubbleSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}