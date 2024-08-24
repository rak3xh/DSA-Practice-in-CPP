#include <iostream>
using namespace std;

bool arraySortedOrNot(int arr[], int n)
{
    // code here
    int count = 0, i = 0;
    while (i < n)
    {
        if (arr[i + 1] > arr[i])
        {
            count++;
            i++;
        }
    }
    if (count == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int a[10];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool ans = arraySortedOrNot(a, n);
    cout << ans;
}