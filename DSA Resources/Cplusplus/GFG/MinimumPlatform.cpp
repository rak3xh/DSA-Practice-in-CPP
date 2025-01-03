#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int n = arr.size(), left = 0, right = 0, pfCount = 0;
        for (int i = 0; i < n; i++)
        {
            int lo = left, hi = n - 1, count = 0;

            while (hi - lo > 1)
            {
                int mid = (lo + hi) / 2;
                if (arr[mid] <= dep[i])
                    lo = mid;
                else
                    hi = mid - 1;
            }

            if (arr[hi] <= dep[i])
                count = (hi - left + 1), right = hi + 1;
            else if (arr[lo] <= dep[i])
                count = (lo - left + 1), right = lo + 1;

            pfCount = max(pfCount, count), left++;
        }

        return pfCount;
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
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number)
        {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}
