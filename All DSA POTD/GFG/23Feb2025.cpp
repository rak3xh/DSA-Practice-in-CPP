#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> s;

        s.push(-1);
        int maxi = INT_MIN;
        for (int i = n - 2; i >= 0; i--)
        {

            s.push(arr[i + 1]);
            maxi = max(maxi, arr[i + 1]);

            if (arr[i] < maxi)
            {
                stack<int> tempstack;
                while (!s.empty())
                {
                    int tope = s.top();
                    if (tope > arr[i])
                    {
                        ans[i] = tope;
                        break;
                    }
                    else
                    {
                        tempstack.push(tope);
                        s.pop();
                    }
                }
                while (!tempstack.empty())
                {
                    s.push(tempstack.top());
                    tempstack.pop();
                }
            }
            else
            {
                ans[i] = -1;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--)
    {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++)
        {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}
