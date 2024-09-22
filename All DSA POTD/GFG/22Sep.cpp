#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution
{
public:
    int lps(string str)
    {
        // Your code goes here
        int i = 0;
        int j = 1;
        vector<int> kmp(str.length(), 0);
        while (j < str.length())
        {
            if (str[i] == str[j])
            {
                i++;
                kmp[j] = i;
                j++;
            }
            else
            {
                if (i == 0)
                {
                    j++;
                }
                else
                {
                    i = kmp[i - 1];
                }
            }
        }
        return kmp[str.length() - 1];
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
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}
