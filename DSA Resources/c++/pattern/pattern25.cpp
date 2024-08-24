#include <iostream>
using namespace std;
int main()
{
    int n, i = 1;
    cin >> n;
    while (i <= n)
    {
        // for spaces
        int space = n - i;
        while (space)
        {
            cout << " ";
            space--;
        }
        // for first triangle
        int num = i;
        int j = 1;
        while (num)
        {
            cout << j;
            j++;
            num--;
        }
        // for the second triangle
        int num2 = i - 1;
        while (num2)
        {
            cout << num2;
            num2--;
        }

        cout << endl;
        i++;
    }
}