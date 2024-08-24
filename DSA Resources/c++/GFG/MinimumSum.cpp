
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string solve(int arr[], int n)
    {
        // code here
        sort(arr, arr + n); // 2 3 4 5 6 8
        string s1, s2;
        string ans;
        int i = n - 1, j = n - 2, carry = 0;
        while (i >= 0 or j >= 0)
        {
            int sum = carry;
            if (i >= 0)
                sum += arr[i];
            if (j >= 0)
                sum += arr[j];
            carry = sum / 10;
            if (sum)
                ans.push_back(sum % 10 + '0');
            i -= 2;
            j -= 2;
        }
        // after addition carry is remain
        if (carry)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans == "" ? "0" : ans;
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}