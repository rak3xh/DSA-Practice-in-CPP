#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int peakElement(vector<int> &arr)
    {
        // Your code here
        int n = arr.size();
        if (n == 1)
            return 0;

        if (arr[0] > arr[1])
            return 0;
        if (arr[n - 1] > arr[n - 2])
            return n - 1;

        int l = 1, r = n - 2;
        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (arr[mid] > arr[mid - 1] && arr[mid + 1] < arr[mid])
                return mid;
            else if (arr[mid] > arr[mid - 1] && arr[mid + 1] > arr[mid])
                l = mid + 1;
            else if (arr[mid] < arr[mid - 1] && arr[mid + 1] < arr[mid])
                r = mid - 1;
            else if (arr[mid] < arr[mid - 1] && arr[mid + 1] > arr[mid])
                l = mid + 1; // or r=mid-1;
        }

        return -1;
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
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            a.push_back(number);
        }

        Solution ob;
        int idx = ob.peakElement(a);
        int n = a.size();
        bool f = 0;
        if (idx < 0 and idx >= n)
            cout << "false" << endl;
        else
        {
            if (n == 1 and idx == 0)
                f = 1;
            else if (idx == 0 and a[0] > a[1])
                f = 1;
            else if (idx == n - 1 and a[n - 1] > a[n - 2])
                f = 1;
            else if (a[idx] > a[idx + 1] and a[idx] > a[idx - 1])
                f = 1;
            else
                f = 0;
            if (f)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}