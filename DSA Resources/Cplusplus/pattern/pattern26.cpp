#include <iostream>
using namespace std;
int main()
{
    int n, i = 1;
    cin >> n;
    while (i <= n)
    {
        // first triangle
        int num = n - i + 1;
        int j = 1;
        while (num)
        {
            cout << j;

            j++;
            num--;
        }
        // second tiangle
        int stars = (2 * i) - 2;
        while (stars)
        {
            cout << "*";
            stars--;
        }
        // third tiangle
        int num2 = n - i + 1;
        while (num2)
        {
            cout << num2;
            num2--;
        }
        cout << "\n";
        i++;
    }
}