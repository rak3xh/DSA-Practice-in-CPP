#include <iostream>
using namespace std;
int main()
{
    int n, i = 2;
    cout << "Enter the number to be checked :";
    cin >> n;
    if (n == 0 || n == 1)
    {
        cout << "0 or 1 cannot be a prime number";
    }
    else
    {
        while (i < n)
        {
            if (n % i == 0)
            {
                cout << n << " is not a prime number!!";
                exit(0);
            }
            else
            {
                i++;
            }
        }
        cout << n << " is a Prime Number!!!";
        return 0;
    }
}
