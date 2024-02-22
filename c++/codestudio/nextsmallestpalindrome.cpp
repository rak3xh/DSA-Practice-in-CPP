#include <bits/stdc++.h>
using namespace std;
string nextSmallerPalindrome(string &s)
{

    if (s == "1")

        return "0";

    int n = s.size();

    int mid = n / 2;

    for (int i = mid; i < n; i++)

    {

        if (s[i] != '0')

        {

            char temp = s[i];

            s[i] = s[n - 1 - i] = temp - 1;

            break;
        }

        else

            s[i] = s[n - 1 - i] = '9';
    }

    if (s[0] == '0')

    {

        s[0] = '9';

        s.pop_back();
    }

    return s;
}
