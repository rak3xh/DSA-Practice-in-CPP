#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int> &arr)
    {
        // Your code goes here.
        map<int, int> mp;
        int n = arr.size();
        vector<int> ans;

        // Counting each element as a value of that element and inserting in the Map
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        // Checking which elements are greater than one-third of total votes and inserting in answer vector
        for (auto it : mp)
        {
            if (it.second > (n / 3))
                ans.push_back(it.first);
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

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num)
        {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty())
        {
            cout << "[]";
        }
        else
        {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}