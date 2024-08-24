#include <bits/stdc++.h>
using namespace std;
string findLastSubstring(string &str)
{
    // Write your code here.
    string substring = "";

    string maxi = "";
    for (int i = str.size() - 1; i >= 0; i--)
    {
        substring = str[i] + substring;
        if (maxi < substring)
        {
            maxi = substring;
        }
    }
    return maxi;
}