#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int n)
{
    int digit, rev = 0;
    while (n != 0)
    {
        digit = n % 10;
        rev = (rev * 10) + digit;
        n = n / 10;
    }
    if (rev == n)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    if (isPalindrome(n))
    {
        cout << "The Number " << n << " is Palinndrome number!!";
    }
    else
    {
        cout << "The Number " << n << " is not a Palinndrome number!!";
    }
}