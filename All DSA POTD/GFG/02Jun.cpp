#include <bits/stdc++.h>
using namespace std;

class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

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
    vector<int> constructList(int q, vector<vector<int>> &queries)
    {
        // code here
        vector<int> arr;
        arr.push_back(0);
        vector<int> xo;
        xo.push_back(0);

        for (auto it : queries)
        {
            if (it[0] == 0)
            {
                arr.push_back(it[1]);
                xo.push_back(0);
            }
            else
            {
                xo[0] = xo[0] ^ it[1];
                if (xo.size() == arr.size())
                    xo.push_back(0);
                xo[xo.size() - 1] = xo[xo.size() - 1] ^ it[1];
            }
        }
        int no = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            no = no ^ xo[i];
            arr[i] = arr[i] ^ no;
        }
        sort(arr.begin(), arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int q;
        scanf("%d", &q);

        vector<vector<int>> queries(q, vector<int>(2));
        Matrix::input(queries, q, 2);

        Solution obj;
        vector<int> res = obj.constructList(q, queries);

        Array::print(res);
    }
}