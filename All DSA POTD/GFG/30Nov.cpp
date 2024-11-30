#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string &s1, string &s2)
    {
        // Your code here
        vector<int> mp(26, 0);
        if (s2.size() > s1.size())
            return false;
        for (int i = 0; i < s2.size(); i++)
        {
            mp[s2[i] - 'a']++;
            mp[s1[i] - 'a']--;
        }
        for (auto s : s2)
        {
            if (mp[s - 'a'] > 0)
            {
                return false;
            }
        }

        return true;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;

    cin >> t;

    while (t--)
    {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}
