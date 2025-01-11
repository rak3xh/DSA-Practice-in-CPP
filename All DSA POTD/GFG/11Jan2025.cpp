#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestUniqueSubstr(string &s)
    {
        // code here
        int ans = 0;
        int i = 0, j = 0;
        int n = s.size();
        map<int, int> mp;
        while (j < n)
        {
            mp[s[j]]++;
            if (mp[s[j]] > 1)
            {
                while (i < j and mp[s[j]] > 1)
                {
                    mp[s[i]]--;
                    i++;
                }
                ans = max(ans, j - i + 1);
                j++;
            }
            else
            {
                ans = max(ans, j - i + 1);
                j++;
            }
        }
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

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}
