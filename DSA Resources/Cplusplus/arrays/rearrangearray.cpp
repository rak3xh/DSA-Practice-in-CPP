#include <iostream>
using namespace std;
int main()
{
    int a[] = {3, 2, 0, 1};
    int b[20];
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        b[i] = a[a[i]];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}