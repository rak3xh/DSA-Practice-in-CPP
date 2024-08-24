#include <iostream>
using namespace std;
int main()
{
    int n, i = 1;
    cin >> n;
    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            char c = 'A' + j - 1;
            cout << c << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}