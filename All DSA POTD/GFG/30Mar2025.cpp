#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*You are required to complete this method*/
class Solution
{
public:
    int startStation(vector<int> &gas, vector<int> &cost)
    {
        // Your code here
        int start = 0;
        int n = gas.size();
        int curr = 0;
        int prev = 0;
        for (int i = 0; i < n; i++)
        {
            curr += gas[i] - cost[i];
            if (curr < 0)
            {
                start = i + 1;
                prev += curr;
                curr = 0;
            }
        }
        return curr + prev >= 0 ? start : -1;
    }
};

//{ Driver Code Starts.
/* Driver program to test above function */
int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--)
    {

        vector<int> gas, cost;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1)
        {
            gas.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2)
        {
            cost.push_back(number2);
        }
        Solution ob;
        int ans = ob.startStation(gas, cost);

        cout << ans << endl;
        cout << "~\n";
    }

    return 0;
}
