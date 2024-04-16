#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    int minimizeDifference(int n, int k, vector<int> &arr)
    {
        // code here
        vector<int> minleft(n, 0), maxleft(n, 0), minright(n, 0), maxright(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                minleft[i] = arr[i];
                maxleft[i] = arr[i];
            }
            else
            {
                minleft[i] = min(minleft[i - 1], arr[i]);
                maxleft[i] = max(maxleft[i - 1], arr[i]);
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                minright[i] = arr[i];
                maxright[i] = arr[i];
            }
            else
            {
                minright[i] = min(minright[i + 1], arr[i]);
                maxright[i] = max(maxright[i + 1], arr[i]);
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i <= n - k; i++)
        {
            int mini = INT_MAX, maxi = INT_MIN;
            int leftInd = i - 1;
            int rightInd = i + k;
            if (leftInd >= 0)
            { // min and max may present at the left of the windwo
                mini = min(mini, minleft[leftInd]);
                maxi = max(maxi, maxleft[leftInd]);
            }

            if (rightInd < n)
            { // min and max may  present at the right side of the window
                mini = min(mini, minright[rightInd]);
                maxi = max(maxi, maxright[rightInd]);
            }
            ans = min(ans, maxi - mini);
        }

        return ans;
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

        int k;
        scanf("%d", &k);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);

        cout << res << endl;
    }
}