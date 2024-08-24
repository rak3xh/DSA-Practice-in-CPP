#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
private:
    bool isPossible(int arr[], int n, int k, long long mid)
    {
        long long PainterCount = 1;
        long long TotalBlock = 0;
        for (long long i = 0; i < n; i++)
        {
            if (TotalBlock + arr[i] <= mid)
            {
                TotalBlock += arr[i];
            }
            else
            {
                PainterCount++;
                if (PainterCount > k || arr[i] > mid)
                {
                    return false;
                }
                TotalBlock = arr[i];
            }
        }
        return true;
    }

public:
    long long minTime(int arr[], int n, int k)
    {
        long long s = 0;
        long long sum = 0;
        for (long long i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        long long e = sum;
        long long mid = s + (e - s) / 2;
        long long ans = 0;
        while (s <= e)
        {
            if (isPossible(arr, n, k, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
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
        int k, n;
        cin >> k >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minTime(arr, n, k) << endl;
    }
    return 0;
}