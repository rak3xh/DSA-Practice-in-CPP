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
            cout << "* ";
            j = j + 1;
        }

        i = i + 1;
        cout << endl;
    }
}