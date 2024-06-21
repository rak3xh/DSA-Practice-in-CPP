#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int satisfied = 0;
        int madeSatisfied = 0;
        int windowSatisfied = 0;

        for (int i = 0; i < customers.size(); ++i)
        {
            if (grumpy[i] == 0)
                satisfied += customers[i];
            else
                windowSatisfied += customers[i];
            if (i >= minutes && grumpy[i - minutes] == 1)
                windowSatisfied -= customers[i - minutes];
            madeSatisfied = max(madeSatisfied, windowSatisfied);
        }

        return satisfied + madeSatisfied;
    }
};