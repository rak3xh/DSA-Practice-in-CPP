#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> bracketNumbers(string str)
    {
        // Your code goes here
        stack<int> st;
        vector<int> res;
        int count = 0;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(')
            {
                count++;
                st.push(count);
                res.push_back(count);
            }
            else if (str[i] == ')')
            {
                int index = st.top();
                st.pop();
                res.push_back(index);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}