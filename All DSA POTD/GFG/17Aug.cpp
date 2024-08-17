#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums)
    {

        // code here
        long long int fact = 1;
        long long int n = nums.size();
        int zeros = 0;
        for (long long int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
                fact *= nums[i];
            else
                zeros++;
        }
        vector<long long int> ans;
        for (long long int i = 0; i < n; i++)
        {
            if ((nums[i] == 0 && zeros > 1) || (nums[i] != 0 && zeros > 0))
                ans.push_back(0);
            else if (nums[i] == 0 && zeros == 1)
                ans.push_back(fact);
            else
                ans.push_back(fact / nums[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}