#include <iostream>
#include <algorithm>
using namespace std;
int firstoccur(int a[], int n, int k)
{

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (a[mid] == k)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (k > a[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int Lastoccur(int a[], int n, int k)
{

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (a[mid] == k)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (k > a[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
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
    int ans1 = firstoccur(a, n, k);
    int ans2 = Lastoccur(a, n, k);
    cout << "\nThe first and last index of " << k << " is :" << ans1 << " & " << ans2;
}