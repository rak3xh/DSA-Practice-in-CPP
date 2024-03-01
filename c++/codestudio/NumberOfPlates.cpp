#include <bits/stdc++.h>

bool countPlatesOnTable(int n, int R, int r)
{

    // Write your code here

    if (n == 1 && r <= R || n == 2 && r * 2 <= R || asin(double(r * 1.0 / (R - r))) * n <= 3.1415927)
    {

        return true;
    }

    return false;
}