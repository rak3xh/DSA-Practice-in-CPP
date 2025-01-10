#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int maximumProfit(vector<int> &prices)
    {
        // code here
        int n = prices.size();
        int profit = 0;
        int i = 0;
        int max_profit = 0;
        int j = 0;
        int result = 0;
        while (i < n)
        {
            for (j = j + 1; j < n; j++)
            {
                profit = prices[j] - prices[i];
                if ((profit > 0) && (max_profit < profit))
                {
                    max_profit = profit;
                }
                else
                {
                    break;
                }
            }
            i = j;
            result += max_profit;
            max_profit = 0;
        }
        return result;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;
        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}