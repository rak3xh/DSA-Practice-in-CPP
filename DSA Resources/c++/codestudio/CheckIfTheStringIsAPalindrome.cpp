#include <bits/stdc++.h>
using namespace std;
bool checkPalindrome(string s)

{

    // Write your code here.

    int i = 0;

    int j = s.size() - 1;

    while (i < j)

    {

        while (i < j && !isalnum(s[i]))

        {

            i++;
        }

        while (i < j && !isalnum(s[j]))

        {

            j--;
        }

        int ans = s[i] - s[j];

        if (ans == 32 || ans == -32 || ans == 0)

        {

            i++;

            j--;
        }

        else

        {

            return false;
        }
    }

    return true;
}