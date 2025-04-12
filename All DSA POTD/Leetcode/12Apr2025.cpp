#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countGoodIntegers(int n, int k)
    {
        const int halfLength = (n + 1) / 2;
        const int minHalf = pow(10, halfLength - 1);
        const int maxHalf = pow(10, halfLength);
        long long ans = 0;
        unordered_set<string> seen;

        for (int num = minHalf; num < maxHalf; ++num)
        {
            string firstHalf = to_string(num);
            string secondHalf(firstHalf.rbegin(), firstHalf.rend());
            string palindrome = firstHalf + secondHalf.substr(n % 2);

            if (stoll(palindrome) % k != 0)
                continue;

            string sortedDigits = palindrome;
            sort(sortedDigits.begin(), sortedDigits.end());

            if (seen.find(sortedDigits) != seen.end())
                continue;

            seen.insert(sortedDigits);

            vector<int> digitCount(10, 0);
            for (char c : palindrome)
                ++digitCount[c - '0'];

            // Leading zeros not allowed, so avoid permutations starting with '0'
            int firstDigitChoices = n - digitCount[0];
            long long permutations = firstDigitChoices * factorial(n - 1);

            for (int freq : digitCount)
                if (freq > 1)
                    permutations /= factorial(freq);

            ans += permutations;
        }

        return ans;
    }

private:
    long long factorial(int n)
    {
        long long res = 1;
        for (int i = 2; i <= n; ++i)
            res *= i;
        return res;
    }
};

// C++ 20 Solution
/*
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    long long countGoodIntegers(int n, int k)
    {
        const int halfLength = (n + 1) / 2;
        const int minHalf = pow(10, halfLength - 1);
        const int maxHalf = pow(10, halfLength);
        long ans = 0;
        unordered_set<string> seen;

        for (int num = minHalf; num < maxHalf; ++num)
        {
            const string firstHalf = to_string(num);
            const string secondHalf = {firstHalf.rbegin(), firstHalf.rend()};
            const string palindrome = firstHalf + secondHalf.substr(n % 2);
            if (stol(palindrome) % k != 0)
            continue;
            string sortedDigits = palindrome;
            ranges::sort(sortedDigits);
            if (seen.contains(sortedDigits))
            continue;
            seen.insert(sortedDigits);
            vector<int> digitCount(10);
            for (const char c : palindrome)
            ++digitCount[c - '0'];
            // Leading zeros are not allowed, so the first digit is special.
            const int firstDigitChoices = n - digitCount[0];
            long permutations = firstDigitChoices * factorial(n - 1);
            // For each repeated digit, divide by the factorial of the frequency since
            // permutations that swap identical digits don't create a new number.
            for (const int freq : digitCount)
            if (freq > 1)
            permutations /= factorial(freq);
            ans += permutations;
        }

        return ans;
    }

    private:
    long factorial(int n)
    {
        long res = 1;
        for (int i = 2; i <= n; ++i)
        res *= i;
        return res;
    }
};
*/