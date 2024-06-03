#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int numberOfConsecutiveOnes(int n)
    {
        // code here
        if (n == 1 || n == 0)
            return 0;
        if (n == 2)
            return 1;
        int mod = 1e9 + 7;
        int sum = 1;
        int t1 = 0;
        int t2 = 1;

        for (int i = 3; i <= n; i++)
        {
            int t = t1 + t2;
            t1 = t2;
            t2 = t % mod;
            sum = ((sum * 2 % mod) + t % mod) % mod;
        }
        return sum % mod;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}
