#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string removeDuplicates(string str)
    {
        // code here
        unordered_set<char> s;
        string ans = "";

        for (int i = 0; i < str.length(); i++)
        {
            if (s.find(str[i]) == s.end())
            {
                ans += str[i];
                s.insert(str[i]);
            }

            else
                continue;
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
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}