#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    int FirstOccur(int a[], int n, int k)
    {
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;
        while (s <= e)
        {
            if (k == a[mid])
            {
                ans = mid;
                e = mid - 1;
            }
            else if (k > a[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }

    int LastOccur(int a[], int n, int k)
    {
        int s = 0;
        int e = n - 1;
        int ans = -1;
        int mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (k == a[mid])
            {
                ans = mid;
                s = mid + 1;
            }
            else if (k > a[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }

public:
    vector<int> find(int arr[], int n, int x)
    {
        // code here
        vector<int> ans;
        int first = FirstOccur(arr, n, x);
        int last = LastOccur(arr, n, x);
        ans.push_back(first);
        ans.push_back(last);
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
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}