#include <bits/stdc++.h>
using namespace std;
int findInteger(int n, int k)
{
    // Write your code here
    int mid = n / 2;

    // If n is odd increase the middle point
    if (n % 2 != 0)
    {
        mid += 1;
    }

    int result = 0;

    // If k is less than middle point
    if (k <= mid)
    {
        // Storing the (k - 1)th odd number
        result = (k - 1) * 2 + 1;
    }
    else
    {
        // Store the offest from middle point in k
        k -= mid;

        // Storing the (k - 1)th even number
        result = (k - 1) * 2 + 2;
    }

    return result;
}
