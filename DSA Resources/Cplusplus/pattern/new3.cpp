#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (j < n - i)
        {
            cout << "*";
            j++;
        }
        i++;
        cout << endl;
    }
    i = 1;
    while (i <= n)
    {
        int j = 0;
        while (j < n - i)
        {
            cout << " ";
            j++;
        }
        while (j < n)
        {
            cout << "*";
            j++;
        }
        i++;
        cout << endl;
    }
}