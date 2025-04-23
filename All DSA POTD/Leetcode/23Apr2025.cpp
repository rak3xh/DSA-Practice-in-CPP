#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countLargestGroup(int n)
    {
        vector<int> count(9 * 4 + 1);
        for (int i = 1; i <= n; ++i)
            ++count[getDigitSum(i)];

        int maxCount = *max_element(count.begin(), count.end());
        return count_if(count.begin(), count.end(), [maxCount](int c)
                        { return c == maxCount; });
    }

private:
    int getDigitSum(int num)
    {
        int digitSum = 0;
        while (num > 0)
        {
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }
};

// C++ 20 Solution
/*
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int countLargestGroup(int n)
    {
        vector<int> count(9 * 4 + 1);
        for (int i = 1; i <= n; ++i)
        ++count[getDigitSum(i)];
        return ranges::count(count, ranges::max(count));
    }

    private:
    int getDigitSum(int num)
    {
        int digitSum = 0;
        while (num > 0)
        {
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }
};
*/