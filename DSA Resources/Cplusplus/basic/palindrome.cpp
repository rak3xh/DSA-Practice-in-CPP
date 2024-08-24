#include <iostream>
using namespace std;
int main()
{
    int num, n;
    cin >> num;
    n = num;
    int rev = 0;
    while (n != 0)
    {
        int digit = n % 10;
        rev = (rev * 10) + digit;
        n = n / 10;
    }
    if (rev == num)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "not Plaindrome";
    }
    return 0;
}