#include <iostream>
#include <algorithm>
using namespace std;
int Binary(int a[], int n, int k)
{
    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2; // for exceeding value of integer from 2^31-1
    while (start <= end)
    {
        if (a[mid] == k)
        {
            return mid;
        }
        if (k > a[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return -1;
}
int main()
{
    int n, a[50], k;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    cout << "The sorted array is :";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Enter the number to be searched : ";
    cin >> k;
    int index = Binary(a, n, k);
    if (index < 0)
    {
        cout << "\nElement Not Found!!!";
    }
    else
    {
        cout << "\nElement " << k << " is found at " << index + 1 << " position !!!";
    }
}