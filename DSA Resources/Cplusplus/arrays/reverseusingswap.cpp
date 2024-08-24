#include <iostream>
using namespace std;
void reverse(int a[], int n)
{
    int start = 0, end = (n - 1);
    while (start <= end)
    {
        swap(a[start], a[end]);
        start++;
        end--;
    }
}
void Display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int n;
    int a[50];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    reverse(a, n);
    Display(a, n);
}
