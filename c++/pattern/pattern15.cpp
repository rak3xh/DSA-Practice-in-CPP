#include <iostream>
using namespace std;
int main()
{
    int n, i = 1;
    char c = 'A';
    cin >> n;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout << c << " ";
            c++;
            j++;
        }
        cout << endl;
        i++;
    }
}