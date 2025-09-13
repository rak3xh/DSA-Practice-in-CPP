#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxFreqSum(string s)
    {
        vector<int> count(26, 0);
        int maxVowel = 0;
        int maxConsonant = 0;

        for (const char c : s)
            ++count[c - 'a'];

        for (const char c : s)
        {
            if (isVowel(c))
                maxVowel = max(maxVowel, count[c - 'a']);
            else
                maxConsonant = max(maxConsonant, count[c - 'a']);
        }

        return maxVowel + maxConsonant;
    }

private:
    bool isVowel(char c)
    {
        static const string vowels = "aeiou";
        return vowels.find(c) != string::npos;
    }
};