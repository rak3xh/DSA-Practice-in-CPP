#include <bits/stdc++.h>

long long int sumOrProduct(long long int n, long long int q)
{
    long long int ans = 0;
    int mod = 1e9 + 7;
    if (q == 1)
    {
        ans = n * (n + 1) / 2;
    }
    else
    {
        ans = 1;
        for (long long int i = 1; i <= n; i++)
            ans = (ans * i) % mod;
    }
    return ans;
}
int main()
{
    long long int n = 32, q = 2;
    long long int ans = sumOrProduct(n, q);
    std::cout << ans;
}