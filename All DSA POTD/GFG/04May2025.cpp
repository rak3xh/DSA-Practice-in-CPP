#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int findSubString(string &str)
    {
        // code here
        int ans = str.size(), sz = unordered_set<char>(str.begin(), str.end()).size();
        unordered_map<char, int> mp;
        int left = 0, right = 0;
        while (right < str.size())
        {
            mp[str[right++]]++;
            if (mp.size() == sz)
            {
                ans = min(ans, right - left);
            }
            while (left < right and mp.size() == sz)
            {
                if (mp[str[left]] == 1)
                {
                    break;
                }
                mp[str[left]]--;
                left++;
                ans = min(ans, right - left);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
//      Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}