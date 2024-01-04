#include <iostream>
using namespace std;
int main()
{
    int n, i = 1;
    cin >> n;
    while (i <= n)
    {
        int space = n - i;
        while (space)
        {
            cout << " ";
            space--;
        }
        int j = i;
        while (j)
        {

            cout << "*";
            j--;
        }
        cout << "\n";
        i++;
    }
}
