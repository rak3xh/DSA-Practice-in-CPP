#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int M = s.size(), N = spaces.size(), l = 0, r = 0;

        string res(M + N, ' ');

        // Iterate over M+N length
        for (int i = 0; i < M + N; i++)
        {

            if (l < N and i == spaces[l] + l)
                l++;
            else
                res[i] = s[r++];
        }

        // Return the required string
        return res;
    }
};