#include <iostream>
using namespace std;
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int occur(int a[], int n, int k)
{
    int s = 0, e = n - 1;
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
        int mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int n, k;
    int a[6] = {1, 2, 3, 3, 4, 5};
    display(a, 6);
    cin >> k;
    int ans = occur(a, 6, k);
    cout << ans;
    return 0;
}