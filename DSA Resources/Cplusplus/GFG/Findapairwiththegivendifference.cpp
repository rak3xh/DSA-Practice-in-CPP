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
    bool findPair(vector<int> &arr, int x)
    {
        // code here
        int n = arr.size();
        if (n == 0)
            return false;

        sort(arr.begin(), arr.end());
        int max_diff = arr[n - 1] - arr[0];
        if (x > max_diff)
            return false;

        int i = 0, j = 1;

        while (i < j && j < n)
        {
            int diff = arr[j] - arr[i];
            if (diff == x && i != j)
                return true;
            else if (diff < x)
                j++;
            else
                i++;
            if (i == j)
                j++;
        }

        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    scanf("%d ", &t);

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
        int k;
        scanf("%d ", &k);
        Solution obj;

        cout << (obj.findPair(arr, k) ? "true" : "false") << endl;
        cout << "~" << endl;
    }
}