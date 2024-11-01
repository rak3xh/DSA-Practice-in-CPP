#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution
{
public:
    long long maxSum(vector<int> &arr)
    {
        // code here
        long long ans = 0;
        sort(arr.begin(), arr.end());
        int i = 0, j = arr.size() - 1;
        int l = 0;
        vector<int> aa;
        aa = arr;
        while (i <= j)
        {
            arr[l++] = aa[i++];
            if (l >= aa.size())
                break;
            arr[l++] = aa[j--];
        }
        for (int i = 1; i < arr.size(); i++)
        {
            ans += abs(arr[i] - arr[i - 1]);
        }
        ans += abs(arr.back() - arr[0]);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--)
    {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num)
        {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}