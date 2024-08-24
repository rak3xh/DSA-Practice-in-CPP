#include <bits/stdc++.h>
using namespace std;
void reverse(string &S, int i, int j)
{

    // by recursion

    if (i > j)
    {

        return;
    }

    swap(S[i], S[j]);

    i++;

    j--;

    reverse(S, i, j);
}
string stringReverse(string S)
{
    // Write your code here.

    reverse(S, 0, S.length() - 1);

    return S;
}