#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n, a[50], count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int check = pow(a[i], 0.5);
        if (check * check == a[i])
        {
            count++;
        }
    }
    cout << count;
}