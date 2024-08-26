#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete this method*/
    bool find(string p, string s, int i, int j, vector<vector<int>> &v)
    {
        if (j < 0 && i < 0)
            return 1;
        if (i < 0)
            return 0;
        if (j < 0)
        {
            while (i >= 0 && p[i] == '*')
                i--;
            if (i < 0)
                return 1;
            else
                return 0;
        }
        if (v[i][j] != -1)
            return v[i][j];
        bool equalorq = 0;
        if (p[i] == s[j] || p[i] == '?')
            equalorq = find(p, s, i - 1, j - 1, v);
        bool aster = 0;
        if (p[i] == '*')
        {
            bool donttake = find(p, s, i - 1, j, v);
            bool take = find(p, s, i, j - 1, v);
            aster = donttake || take;
        }
        return v[i][j] = equalorq || aster;
    }
    int wildCard(string pattern, string str)
    {
        // code here
        int n = str.length() - 1, m = pattern.length() - 1;
        vector<vector<int>> v(m + 1, vector<int>(n + 1, -1));
        return find(pattern, str, m, n, v);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}