#include <iostream>
using namespace std;
int findProductSumDifference(int n)
{
    // Write your code here
    int sum = 0;
    long long int prod = 1;
    while (n != 0)
    {
        int digit = n % 10;
        sum += digit;
        prod *= digit;
        n = n / 10;
    }
    return prod - sum;
}
int main()
{
    int n;
    cin >> n;
    int ans = findProductSumDifference(n);
    cout << ans;
}