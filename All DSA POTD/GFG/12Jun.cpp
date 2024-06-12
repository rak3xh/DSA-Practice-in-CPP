#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countNumberswith4(int n)
    {
        // code here
        int count = 0; // Initialize the counter to 0
        for (int i = 1; i <= n; i++)
        {                             // Loop through all numbers from 1 to n
            string st = to_string(i); // Convert the current number to a string
            for (int j = 0; j < st.size(); j++)
            { // Loop through each character of the string
                if (st[j] == '4')
                {               // Check if the current character is '4'
                    count += 1; // Increment the counter if '4' is found
                    break;      // Exit the inner loop since we only need to count each number once
                }
            }
        }
        return count; // Return the total count of numbers containing '4'
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}
