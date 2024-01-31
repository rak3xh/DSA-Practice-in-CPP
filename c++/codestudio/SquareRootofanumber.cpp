#include <iostream>
using namespace std;
long long int sqrt(int n)
{
    int s = 0, e = n;
    long long int mid = s + (e - s) / 2;
    long long int ans = -1;
    while (s <= e)
    {
        long long int square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        else if (square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int floorSqrt(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return sqrt(n);
}
