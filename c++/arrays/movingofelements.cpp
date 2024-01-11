#include <iostream>
using namespace std;
void Swap(int a[], int n)
{
    int start = 0;
    int next = start + 1;

    while (start < (n - 1))
    {
        swap(a[start], a[next]);
        start++;
        next++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n, a[50];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Swap(a, n);
    Swap(a, n);
    Swap(a, n);
}