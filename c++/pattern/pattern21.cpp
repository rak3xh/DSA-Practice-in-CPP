#include <iostream>
using namespace std;
int main()
{
    int n, i = 1;
    cin >> n;
    while (i <= n)
    {
        int space = i - 1;
        while (space)
        {
            cout << " ";
            space--;
        }
        int stars = n - i + 1;

        while (stars)
        {
            cout << i;
            stars--;
        }
        cout << "\n";
        i++;
    }
}
