#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    int longestSubseq(int n, vector<int> &a)
    {
        // code here
        map<int, int> dp;
        int ans = 1;

        for (size_t i = 0; i < n; i++)
        {
            dp[a[i]] = max(dp[a[i]], 1);

            if (dp.count(a[i] - 1))
                dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);

            if (dp.count(a[i] + 1))
                dp[a[i]] = max(dp[a[i]], dp[a[i] + 1] + 1);

            ans = max(ans, dp[a[i]]);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}
