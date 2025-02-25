#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int getMaxArea(vector<int> &arr)
    {
        // Your code here
        stack<int> st;
        int max_area = 0;
        int n = arr.size();

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || arr[i] < arr[st.top()]))
            {
                int height = arr[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }

        return max_area;
    }
};

//{ Driver Code Starts.

int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}
