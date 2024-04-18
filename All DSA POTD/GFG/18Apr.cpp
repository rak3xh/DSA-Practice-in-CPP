#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int arr[], int n)
    {
        // Your code here
        unordered_set<int> st;
        vector<int> v;
        for (int i = 0; i < n + 2; i++)
        {
            if (st.find(arr[i]) != st.end())
            {
                v.push_back(arr[i]);
                if (v.size() == 2)
                {
                    break;
                }
            }
            st.insert(arr[i]);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        int a[n + 2];

        for (int i = 0; i < n + 2; i++)
            cin >> a[i];

        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}
