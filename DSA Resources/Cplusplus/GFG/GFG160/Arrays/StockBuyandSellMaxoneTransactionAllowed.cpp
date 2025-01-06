#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maximumProfit(vector<int> &prices)
    {
        // code here
        // setting maximum profit
        int maxPr = 0;
        // get the lowest price to buy
        int low = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            int profit = 0;
            // if current price is greater than the lowest then calculate profit else update lowest buy value
            if (prices[i] > low)
            {
                low = min(low, prices[i - 1]);
                profit = prices[i] - low;
            }
            else
            {
                low = min(low, prices[i]);
            }
            // get the maximum profit
            maxPr = max(maxPr, profit);
        }
        return maxPr;
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
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}
