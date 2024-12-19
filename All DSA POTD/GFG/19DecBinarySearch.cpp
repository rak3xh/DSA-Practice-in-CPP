#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int kthMissing(vector<int> &arr, int k)
    {
        // Your code goes here
        int n = arr.size();
        int l = 0, r = n - 1;
        if (arr[0] > k)
            return k;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            // count of numbers missing till this point at index =mid
            int mCount = arr[mid] - (mid + 1);
            if (mCount < k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (r == -1)
            return k;
        return k + r + 1;
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
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}