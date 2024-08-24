#include <iostream>
#include <algorithm>
using namespace std;
int firstoccur(int a[], int n, int k)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans1 = -1;
    while (s <= e)
    {
        if (a[mid] == k)
        {
            ans1 = mid;
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
    return ans1;
}
int Lastoccur(int a[], int n, int k)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans2 = -1;
    while (s <= e)
    {
        if (a[mid] == k)
        {
            ans2 = mid;
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
    return ans2;
}

int main()
{
    int n, k, a[50];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    cout << "Searched :";
    cin >> k;
    int first = firstoccur(a, n, k);
    int last = Lastoccur(a, n, k);
    int occurences = (last - first) + 1;
    cout << "The total occurences of the given number " << k << " is: " << occurences;
}