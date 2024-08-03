
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &mat)
    {
        // code here
        int prob_celeb = -1;
        for (int i = 0; i < mat.size(); i++)
        {
            int row_sum = 0;
            for (int j = 0; j < mat.size(); j++)
            {
                if (i == j)
                    continue;
                else if (mat[i][j] == 1)
                    row_sum++;
            }
            if (row_sum == 0)
                prob_celeb = i;
        }
        if (prob_celeb == -1)
            return -1;
        int peolple_knows = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
            {
                if (j == prob_celeb && i != j && mat[i][j] == 1)
                {
                    peolple_knows++;
                }
            }
        }
        if (peolple_knows == mat.size() - 1)
            return prob_celeb;
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}