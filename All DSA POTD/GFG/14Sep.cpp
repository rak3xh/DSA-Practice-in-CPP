#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void rearrange(vector<int> &arr)
    {
        // code here
        vector<int> positive;
        vector<int> negative;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] < 0)
                negative.push_back(arr[i]);
            else
                positive.push_back(arr[i]);
        }

        arr.clear();

        int p = 0;
        int n = 0;

        while (p < positive.size() && n < negative.size())
        {
            arr.push_back(positive[p]);
            p++;

            arr.push_back(negative[n]);
            n++;
        }

        while (p < positive.size())
        {
            arr.push_back(positive[p]);
            p++;
        }

        while (n < negative.size())
        {
            arr.push_back(negative[n]);
            n++;
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num)
        {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
