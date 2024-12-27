#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {
        // Code here
        unordered_map<int, int> mp;
        int ans = 0;
        for (auto it : arr)
        {
            int num = target - it;
            if (mp.find(num) != mp.end())
            {
                // exists
                ans += mp[num];
            }

            mp[it]++;
        }

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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl
             << "~" << endl;
    }
    return 0;
}