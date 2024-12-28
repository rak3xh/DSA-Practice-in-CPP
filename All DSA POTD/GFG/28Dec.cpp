#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<vector<int>> findTriplets(vector<int> &arr)
    {
        // Code here
        unordered_map<int, vector<pair<int, int>>> mpp;
        set<vector<int>> st;

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                int sum = arr[i] + arr[j];
                mpp[sum].push_back({i, j});
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {

            int req = -arr[i];
            if (mpp.find(req) != mpp.end())
            {
                for (auto it : mpp[req])
                {
                    if (i != it.first && i != it.second)
                    {
                        vector<int> curr = {i, it.first, it.second};
                        sort(curr.begin(), curr.end());
                        st.insert(curr);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
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

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0)
        {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}