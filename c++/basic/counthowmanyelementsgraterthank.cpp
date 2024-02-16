#include <iostream>
using namespace std;
int main()
{
    int n, a[50], count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > k)
        {
            count++;
        }
    }
    cout << count;
}