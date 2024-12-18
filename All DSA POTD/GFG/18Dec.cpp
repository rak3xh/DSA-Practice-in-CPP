#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int isP(int maxi, vector<int> &arr, int n, int m)
    {
        int cnt = 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + arr[i] <= maxi)
            {
                sum += arr[i];
            }
            else
            {
                cnt++;
                sum = arr[i];
            }
        }
        return cnt;
    }

    // Function to find minimum number of pages.
    int solve(vector<int> &A, int N, int M)
    {
        // code here
        if (N < M)
            return -1;
        int hi = A[0];
        int lo = A[0];
        for (int i = 1; i < N; i++)
        {
            hi += A[i];
            lo = max(lo, A[i]);
        }

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (isP(mid, A, N, M) > M)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return lo;
    }
    int findPages(vector<int> &arr, int k)
    {
        // code here
        return solve(arr, arr.size(), k);
    }
};

//{ Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--)
    {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number)
        {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}