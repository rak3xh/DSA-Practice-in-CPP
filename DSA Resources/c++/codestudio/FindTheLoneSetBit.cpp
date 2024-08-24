#include <bits/stdc++.h>
using namespace std;
int findSetBit(int N)
{
    // Write your code here
    int c = 0, i = 0;

    while (N != 0)
    {

        if (N & 1)
        {

            c++; // total number of 1;
        }

        N = N >> 1;
        i++; // position for 1
    }

    if (c == 1)
    {

        return i; // single on is present 'i' is the position
    }

    else
    {

        return -1; // if no 1 is present or 2 or more than 2 number of ones is present
    }
}
