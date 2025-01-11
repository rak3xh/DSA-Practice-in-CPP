#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int fib(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);

    return dp[n];
}
int nthFibonacci(int n)
{
    vector<int> dp(n + 1, -1);
    return fib(n, dp);
}
int main()
{
    int n;
    cin >> n;

    cout << nthFibonacci(n);
    getch();
}