#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int solve(string A, unordered_set<string> &hm, int index, vector<int> &dp)
    {
        dp[A.size()] = 1;
        for (int index = A.size() - 1; index >= 0; index--)
        {
            string temp = "";
            for (int i = index; i < A.size(); i++)
            {
                temp += A[i];
                if (dp[i + 1] && hm.find(temp) != hm.end())
                {
                    dp[index] = 1;
                    break;
                }
            }
        }
        return dp[0];
    }
    int wordBreak(string A, vector<string> &B)
    {
        // code here
        unordered_set<string> hm(B.begin(), B.end());
        vector<int> dp(A.size() + 1, 0);
        return solve(A, hm, 0, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";
    }
}