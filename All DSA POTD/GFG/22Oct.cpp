#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int sameOccurrence(vector<int> &arr, int x, int y)
    {
        // code here
        int count = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1;
        for (auto i : arr)
        {
            if (i == x)
            {
                sum++;
            }
            else if (i == y)
            {
                sum--;
            }

            count += mp[sum];
            mp[sum]++;
        }

        return count;
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
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}