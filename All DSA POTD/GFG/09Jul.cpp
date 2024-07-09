#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution
{
public:
    int threeSumClosest(vector<int> arr, int target)
    {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = -1, minDiff = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int L = i + 1, R = n - 1;

            int currSum = 0;

            while (L < R)
            {
                int currSum = arr[i] + arr[L] + arr[R];
                int currDiff = abs(currSum - target);

                if (currDiff < minDiff)
                {
                    minDiff = currDiff;
                    ans = currSum;
                }
                else if (currDiff == minDiff)
                {
                    ans = max(ans, currSum);
                }

                if (currSum > target)
                    R--;
                else if (currSum == target)
                    return target;
                else
                    L++;
            }
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
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}