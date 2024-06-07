#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx)
    {

        // Your code here
        unordered_map<int, int> mp;

        // Using the difference array concept with unordered_map
        for (int i = 0; i < n; ++i)
        {
            mp[l[i]] += 1;
            mp[r[i] + 1] -= 1;
        }

        int max_occurrences = 0;
        int max_occurred_element = INT_MIN;
        int current_count = 0;

        // Iterate over the range to find the maximum occurred integer
        for (int i = 0; i <= maxx; ++i)
        {
            current_count += mp[i];
            if (current_count > max_occurrences)
            {
                max_occurrences = current_count;
                max_occurred_element = i;
            }
        }

        return max_occurred_element;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;

    // taking testcases
    cin >> t;

    while (t--)
    {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++)
        {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++)
        {

            cin >> r[i];
            if (r[i] > maxx)
            {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}