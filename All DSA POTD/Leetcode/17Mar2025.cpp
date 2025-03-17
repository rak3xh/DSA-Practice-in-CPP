// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        vector<int> count(501, 0);

        for (const int num : nums)
            ++count[num];

        return all_of(count.begin(), count.end(), [](int c)
                      { return c % 2 == 0; });
    }
};

// C++ 20 Solution
/*
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool divideArray(vector<int> &nums)
    {
        vector<int> count(501);

        for (const int num : nums)
        ++count[num];

        return ranges::all_of(count, [](int c)
        { return c % 2 == 0; });
    }
};
*/