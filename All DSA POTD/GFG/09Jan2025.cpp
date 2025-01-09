#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        // code here
        int sum = 0;

        int start = 0;

        for (int i = 0; i < arr.size(); i++)
        {

            sum += arr[i];

            while (sum > target && start < i)
            {

                sum -= arr[start];

                start++;
            }

            while (sum == target)
            {

                return {start + 1, i + 1};
            }
        }

        return {-1};
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
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result)
        {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}
