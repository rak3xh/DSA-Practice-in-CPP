#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long kMirror(int k, int n)
    {
        long long ans = 0;
        vector<char> A = {'0'};

        for (int count = 0; count < n; ++count)
        {
            while (true)
            {
                A = nextKMirror(A, k);
                long long num = toBase10(A, k);
                if (isDecimalPalindrome(num))
                {
                    ans += num;
                    break;
                }
            }
        }

        return ans;
    }

private:
    vector<char> nextKMirror(vector<char> &A, int k)
    {
        int len = A.size();
        for (int i = len / 2; i < len; ++i)
        {
            int nextNum = A[i] - '0' + 1;
            if (nextNum < k)
            {
                A[i] = '0' + nextNum;
                A[len - 1 - i] = '0' + nextNum;
                for (int j = len / 2; j < i; ++j)
                {
                    A[j] = '0';
                    A[len - 1 - j] = '0';
                }
                return A;
            }
        }
        vector<char> newA(len + 1, '0');
        newA[0] = newA[len] = '1';
        return newA;
    }

    long long toBase10(const vector<char> &A, int k)
    {
        long long result = 0;
        for (char c : A)
        {
            result = result * k + (c - '0');
        }
        return result;
    }

    bool isDecimalPalindrome(long long num)
    {
        string s = to_string(num);
        return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
    }
};