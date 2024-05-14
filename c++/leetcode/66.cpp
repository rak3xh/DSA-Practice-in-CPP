#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    vector<int> plusOne(vector<int> &digits)
    {

        int n = digits.size();

        for (int i = n - 1; i >= 0; i--)
        {

            if (digits[i] < 9)
            {

                digits[i]++;

                return digits;
            }

            else
            {

                digits[i] = 0;
            }
        }

        vector<int> ans;

        ans.push_back(1);

        for (int i = 0; i < n; i++)
        {

            ans.push_back(digits[i]);
        }

        return ans;
    }
};