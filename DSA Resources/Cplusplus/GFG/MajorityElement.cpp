#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {

        // your code here
        unordered_map<int, int> mp;
        int ans = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
            if (mp[arr[i]] > arr.size() / 2)
            {
                ans = arr[i];
            }
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
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}
