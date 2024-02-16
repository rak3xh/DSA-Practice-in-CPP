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
    if (k == 0)
    {
        cout << "Nothing can be divided by zero!!" << endl;
    }
    else if (k == 1)
    {
        cout << n << endl;
    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            if (a[i] % k == 0)
            {
                count++;
            }
        }
        cout << count;
    }
}