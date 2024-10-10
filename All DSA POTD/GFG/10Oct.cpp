#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maxDistance(vector<int> &arr)
    {
        // Code here
        int maxi = -1e9;
        unordered_map<int, int> mpp;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            if (mpp.find(arr[i]) != mpp.end())
            {
                maxi = max(maxi, i - mpp[arr[i]]);
            }
            else
                mpp[arr[i]] = i;
        }
        return maxi;
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

        stringstream s1(input);
        int num;
        while (s1 >> num)
        {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}