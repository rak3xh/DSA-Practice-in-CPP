#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int myAtoi(char *s)
    {
        // Your code here
        long long ans = 0;
        int i = 0, n = strlen(s);
        int sign = 1; // Default to positive

        // Skip leading spaces
        while (i < n && (s[i] == ' ' || s[i] == '0'))
            i++;

        // Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Process digits
        while (i < n && s[i] >= '0' && s[i] <= '9')
        {
            ans = ans * 10 + (s[i] - '0');

            // Check for overflow
            if (ans * sign > INT_MAX)
                return INT_MAX;
            if (ans * sign < INT_MIN)
                return INT_MIN;

            i++;
        }

        return ans * sign;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}