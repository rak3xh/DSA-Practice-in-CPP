#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q)
    {
        // Your code goes here;
        vector<int> ans;
        sort(b.begin(), b.end());

        for (int i = 0; i < query.size(); i++)
        {

            int index = query[i];
            int val = a[index];
            int cnt = upper_bound(b.begin(), b.end(), val) - b.begin();

            ans.push_back(cnt);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;

    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++)
        {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++)
        {
            cout << ans[i] << endl;
        }
    }
    return 0;
}