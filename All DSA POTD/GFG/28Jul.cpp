#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string removeDups(string str)
    {
        // Your code goes here
        unordered_map<char, int> mp;

        string S = "";

        for (int i = 0; i < str.length(); i++)
        {
            mp[str[i]]++;

            if (mp[str[i]] == 1)
                S += str[i];
        }
        return S;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}