#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

int nthFibonacci(int n)
{

    // Using Tabulation and Space optimization
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    vector<int> dp(2);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int next_number = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = next_number;
    }
    return dp[1];
}
int main()
{
    int n;
    cin >> n;

    cout << nthFibonacci(n);
    getch();
}