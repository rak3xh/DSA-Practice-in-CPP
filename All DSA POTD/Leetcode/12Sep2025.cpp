#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool doesAliceWin(string s)
    {
        for (char c : s)
        {
            if (isVowel(c))
                return true;
        }
        return false;
    }

private:
    bool isVowel(char c)
    {
        static const string vowels = "aeiou";
        return vowels.find(c) != string::npos;
    }
};