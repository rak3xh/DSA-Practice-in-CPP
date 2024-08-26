#include <bits/stdc++.h>
using namespace std;
int isSorted(int n, int a[])
{
    // Write your code here.
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < a[i + 1] || a[i] == a[i + 1])
        {
            counter++;
            cout << counter << " ";
        }
    }
    cout << "end of counter" << endl;
    if (counter == n)
        return 1;
    else
        return 0;
}
int main()
{
    int n, a[20];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << isSorted(n, a);
}
