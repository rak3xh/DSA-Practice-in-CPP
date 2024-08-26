#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    static void factorial(long long n, long long i, long long fact, vector<long long> &result)
    {
        if (fact > n)
            return;
        result.push_back(fact);
        factorial(n, i + 1, fact * (i + 1), result);
    }
    vector<long long> factorialNumbers(long long n)
    {
        // Write Your Code here
        vector<long long> ans;
        factorial(n, 1, 1, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}