#include <bits/stdc++.h>
using namespace std;
bool isStrobogrammatic(string &n)

{

    int len = n.length();

    for (int i = 0; i < len; i++)
    {

        if (n[i] != '6' && n[i] != '8' && n[i] != '9' && n[i] != '0' && n[i] != '1')
        {

            return false;
        }
    }

    int j = len - 1;

    int i = 0;

    while (i <= j)
    {

        if ((n[i] == '8' && n[j] == '8') || (n[i] == '6' && n[j] == '9') || (n[i] == '1' && n[j] == '1') ||

            (n[i] == '9' && n[j] == '6') || (n[i] == '0' && n[j] == '0'))
        {

            i++, j--;
        }
        else
        {

            return false;
        }
    }

    return true;
}
