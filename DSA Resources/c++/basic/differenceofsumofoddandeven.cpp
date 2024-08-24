#include <iostream>
using namespace std;
int Difference(int a[], int n)
{
    int oddSum = 0, evenSum = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] & 1) == 1)
        {
            oddSum += a[i];
        }
        else
        {
            evenSum += a[i];
        }
    }
    return (evenSum - oddSum);
}
int main()
{
    int n;
    cin >> n;
    int a[50];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = Difference(a, n);
    cout << ans;
}