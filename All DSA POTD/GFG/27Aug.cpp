#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr)
    {
        // Your code here
        int n = arr.size();
        int ls[n];
        ls[0] = 0;
        int rs[n];
        rs[n - 1] = 0;

        for (int i = 1; i < n; i++)
        {
            int j = i - 1, small = arr[i];
            while (j >= 0)
            {
                if (arr[j] < small)
                {
                    small = arr[j];
                    break;
                }
                j--;
            }
            if (small == arr[i])
            {
                ls[i] = 0;
            }
            else
                ls[i] = small;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            int j = i + 1, small = arr[i];
            while (j < n)
            {
                if (arr[j] < small)
                {
                    small = arr[j];
                    break;
                }
                j++;
            }
            if (small == arr[i])
            {
                rs[i] = 0;
            }
            else
                rs[i] = small;
        }
        int maxi = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = abs(ls[i] - rs[i]);
            maxi = max(maxi, sum);
        }
        return maxi;
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
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num)
        {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}