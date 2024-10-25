#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    vector<int> alternateSort(vector<int> &arr)
    {
        // Your code goes here
        int n = arr.size();
        if (n == 1)
            return arr;
        sort(arr.begin(), arr.end());
        vector<int> ans(n);
        int ind = n - 1;
        for (int i = 0; i < n; i += 2)
        {
            ans[i] = arr[ind--];
        }
        ind = 0;
        for (int i = 1; i < n; i += 2)
        {
            ans[i] = arr[ind++];
        }
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
        Solution obj;
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
