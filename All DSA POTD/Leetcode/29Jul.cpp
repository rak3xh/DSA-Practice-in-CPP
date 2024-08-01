#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int ans = 0;

        for (int i = 1; i < rating.size() - 1; ++i)
        {
            // Calculate soldiers on the left with less/greater ratings.
            int leftLess = 0;
            int leftGreater = 0;
            for (int j = 0; j < i; ++j)
                if (rating[j] < rating[i])
                    ++leftLess;
                else if (rating[j] > rating[i])
                    ++leftGreater;
            // Calculate soldiers on the right with less/greater ratings.
            int rightLess = 0;
            int rightGreater = 0;
            for (int j = i + 1; j < rating.size(); ++j)
                if (rating[j] < rating[i])
                    ++rightLess;
                else if (rating[j] > rating[i])
                    ++rightGreater;
            ans += leftLess * rightGreater + leftGreater * rightLess;
        }

        return ans;
    }
};