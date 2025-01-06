#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr)
    {

        // your code here
        int max_so_far = 0;
        int min_so_far = 0;
        int minSum = arr[0];
        int maxSum = arr[0];
        int total = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            max_so_far = max(max_so_far + arr[i], arr[i]);
            maxSum = max(maxSum, max_so_far);

            min_so_far = min(min_so_far + arr[i], arr[i]);
            minSum = min(minSum, min_so_far);

            total += arr[i];
        }
        return max(total - minSum, maxSum);
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
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}
