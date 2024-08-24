#include <iostream>
using namespace std;
int main()
{
    int n, i = 1;
    cin >> n;
    while (i <= n)
    {
        int j = 1;
        char c = 'A' + i - 1;
        while (j <= n)
        {
            cout << c << " ";
            c++;
            j++;
        }
        cout << endl;
        i++;
    }
}