#include <bits/stdc++.h>
using namespace std;

string addBinaryString(string &a, string &b, int n, int m)
{
    int carry = 0, i = n - 1, j = m - 1;
    string ans;

    while (i >= 0 and j >= 0)
    {
        if ((a[i] == '1' and b[j] == '0') or (a[i] == '0' and b[j] == '1'))
        {
            if (carry)
                ans += '0';
            else
                ans += '1';
        }
        else if (a[i] == '1' and b[j] == '1')
        {
            if (carry)
                ans += '1';
            else
                ans += '0', carry = 1;
        }
        else if (a[i] == '0' and b[j] == '0')
        {
            if (carry)
                ans += '1', carry = 0;
            else
                ans += '0';
        }

        i--, j--;
    }

    while (i >= 0)
    {
        if (a[i] == '1')
        {
            if (carry)
                ans += '0';
            else
                ans += '1';
        }
        else
        {
            if (carry)
                ans += '1', carry = 0;
            else
                ans += '0';
        }
        i--;
    }

    while (j >= 0)
    {
        if (b[j] == '1')
        {
            if (carry)
                ans += '0';
            else
                ans += '1';
        }
        else
        {
            if (carry)
                ans += '1', carry = 0;
            else
                ans += '0';
        }
        j--;
    }

    if (carry)
        ans += '1', carry = 0;

    reverse(ans.begin(), ans.end());
    int k = 0;
    while (k < ans.size() and ans[k] == '0')
        k++;

    return ans.substr(k);
}