#include <iostream>
using namespace std;
void reverse(int a[], int n)
{
    for (int i = (n - 1); i >= 0; i--)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[50], n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    reverse(a, n);
}