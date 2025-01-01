// C++ 14 Solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(string s)
    {
        int ans = 0;
        int zeros = 0;
        int ones = count(s.begin(), s.end(), '1'); // Replaced ranges::count with std::count

        for (int i = 0; i + 1 < s.size(); ++i)
        {
            if (s[i] == '0')
                ++zeros;
            else
                --ones;
            ans = max(ans, zeros + ones);
        }

        return ans;
    }
};

// C++ 20 Solution

/*
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScore(string s)
    {
        int ans = 0;
        int zeros = 0;
        int ones = ranges::count(s, '1');

        for (int i = 0; i + 1 < s.size(); ++i)
        {
            if (s[i] == '0')
                ++zeros;
            else
                --ones;
            ans = max(ans, zeros + ones);
        }

        return ans;
    }
};
*/