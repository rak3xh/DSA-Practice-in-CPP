#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();

        int count = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int add = arr[i] + k;
            int sub = arr[i] - k;
            count += mp[add];
            count += mp[sub];
            mp[arr[i]]++;
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
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}