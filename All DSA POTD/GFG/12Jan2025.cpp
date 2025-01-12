#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        // code here
        int ans = 0;
        vector<int> p, s(arr.size(), 0);
        for (int i = 0; i < arr.size(); i++)
        {
            if (i == 0)
            {
                p.push_back(arr[i]);
                s[arr.size() - 1] = arr[arr.size() - 1];
            }
            else
            {
                p.push_back(max(p.back(), arr[i]));
                s[arr.size() - 1 - i] = max(arr[arr.size() - 1 - i], s[arr.size() - i]);
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            ans += min(p[i], s[i]) - arr[i];
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl
             << "~" << endl;
    }
    return 0;
}
