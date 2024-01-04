#include <iostream>
using namespace std;
int main()
{
    int n, i = 1;
    cin >> n;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            char c = 'A' + i - 1;
            cout << c;
            j++;
        }
        cout << endl;
        i++;
    }
}