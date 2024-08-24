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
        int num = n - i + 1;

        while (num)
        {
            cout << n - num + 1;
            num--;
        }
        cout << "\n";
        i++;
    }
}
