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
    bool isPrime(int x)
    {
        if (x <= 1)
            return false; // 0 and 1 are not prime numbers
        if (x <= 3)
            return true; // 2 and 3 are prime numbers
        if (x % 2 == 0 || x % 3 == 0)
            return false;
        for (int i = 5; i * i <= x; i += 6)
        {
            if (x % i == 0 || x % (i + 2) == 0)
                return false;
        }
        return true;
    }
    vector<int> getPrimes(int n)
    {
        // code here
        for (int i = 2; i <= n / 2; i++)
        {
            if (isPrime(i) && isPrime(n - i))
            {
                return {i, n - i};
            }
        }

        // If no pairs are found, return an empty vector (or handle it as needed)
        return {-1, -1};
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
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}