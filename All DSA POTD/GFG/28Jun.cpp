#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string pattern(vector<vector<int>> &arr)
    {
        // Code Here
        int n = arr.size();

        // Check rows for palindromes
        for (int i = 0; i < n; i++)
        {
            bool isPalindrome = true;
            for (int j = 0, k = n - 1; j < k; j++, k--)
            {
                if (arr[i][j] != arr[i][k])
                {
                    isPalindrome = false;
                    break;
                }
            }
            if (isPalindrome)
            {
                return to_string(i) + " R";
            }
        }

        // Check columns for palindromes
        for (int i = 0; i < n; i++)
        {
            bool isPalindrome = true;
            for (int j = 0, k = n - 1; j < k; j++, k--)
            {
                if (arr[j][i] != arr[k][i])
                {
                    isPalindrome = false;
                    break;
                }
            }
            if (isPalindrome)
            {
                return to_string(i) + " C";
            }
        }

        // No palindrome found
        return "-1";
    }
};

//{ Driver Code Starts.

int main()
{

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}