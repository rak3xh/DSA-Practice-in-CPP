#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool kPangram(string str, int k)
    {
        // code here
        unordered_map<char, int> m;
        int count = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != ' ')
            {
                count++;
                m.insert({str[i], 1});
            }
        }
        return (26 - m.size() <= count - m.size() && 26 - m.size() <= k) ? true : false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}