#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countWays(string s1, string s2)
    {
        // code here
        int mod = 1e9 + 7;
        int n = s1.length(), m = s2.length();

        // Create an array to store the count of distinct subsequences for each character in s2
        vector<int> prev(m + 1, 0);

        // Initialize the count for an empty string (base case)
        prev[0] = 1;

        // Iterate through s1 and s2 to calculate the counts
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            { // Iterate in reverse direction to avoid overwriting values prematurely
                if (s1[i - 1] == s2[j - 1])
                {
                    // If the characters match, we have two options:
                    // 1. Match the current characters and add to the previous count (prev[j-1])
                    // 2. Leave the current character in s1 and match s2 with the previous characters (prev[j])
                    prev[j] = (prev[j - 1] + prev[j]) % mod;
                }
                // No need for an else statement since we can simply leave the previous count as is
            }
        }

        // The value at prev[m] contains the count of distinct subsequences
        return prev[m];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}
