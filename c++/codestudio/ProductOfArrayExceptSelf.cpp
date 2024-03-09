#include <bits/stdc++.h>
#define LL long long
using namespace std;
int *getProductArrayExceptSelf(int *arr, int n)
{
    int *ans = new int[n];
    int temp = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] = temp;
        // update temp
        temp = (1LL * temp * arr[i]) % 1000000007;
    }
    temp = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = (1LL * ans[i] * temp) % 1000000007;
        // update temp
        temp = (1LL * temp * arr[i]) % 1000000007;
    }
    return ans;
}
