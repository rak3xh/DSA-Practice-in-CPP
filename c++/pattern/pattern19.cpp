#include <iostream>
using namespace std;
int main()
{
    int n, i = 1;
    cin >> n;
    while (i <= n)
    {
        int star = n - i + 1;
        while (star)
        {
            cout << "*"
                 << " ";
            star--;
        }

        cout << "\n";
        i++;
    }
}