#include <iostream>
using namespace std;
int pivotfind(int a[], int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (a[mid] >= a[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
int main()
{
    int a[50], n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int pivot = pivotfind(a, n);
    cout << "The pivot Element Index is :" << pivot;
}