#include <iostream>
using namespace std;
long long int sqrtInt(int n)
{
    int s = 0, e = n;
    long int mid = s + (e - s) / 2;

    long long int ans = -1;
    while (s <= e)
    {
        long long int power = mid * mid;
        if (power == n)
        {
            return mid;
        }
        else if (power < n)
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
double morePresicion(int n, int presicion, int tempSoln)
{
    double factor = 1;
    double ans = tempSoln;
    for (int i = 0; i < presicion; i++)
    {
        factor /= 10;
        for (double j = ans; j * j < n; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int tempSoln = sqrtInt(n);
    cout << "The ans is : " << morePresicion(n, 4, tempSoln);
}