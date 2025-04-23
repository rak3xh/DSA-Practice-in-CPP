#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> singleNum(vector<int> &arr)
    {
        // Code here.
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto it : arr)
        {
            mp[it] += 1;
        }
        for (auto it : mp)
        {
            if (it.second == 1)
                ans.push_back(it.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--)
    {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}