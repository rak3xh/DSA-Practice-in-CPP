#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int isValid(string str)
    {
        // code here
        int n = str.size();
        int dot = 0;
        string tmp = "";
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '.')
            {
                dot++;
                if (tmp.empty() || (tmp[0] == '0' && tmp.size() > 1))
                {
                    return false;
                }
                int num = stoi(tmp);
                if (num < 0 || num > 255)
                {
                    return false;
                }
                tmp = "";
            }
            else
            {
                tmp += str[i];
            }
        }
        if (dot != 3)
            return false;
        if (tmp.empty() || (tmp[0] == '0' && tmp.size() > 1))
            return false;
        int num = stoi(tmp);
        if (num < 0 || num > 255)
            return false;
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}