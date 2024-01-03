#include <iostream>
using namespace std;
int main()
{
    int n, i = 1;
    cin >> n;
    while (i <= n)
    {
        int j = i;
        while (j < 2 * i)
        {
            cout << j << " ";

            j++;
        }
        cout << endl;
        i++;
    }
}