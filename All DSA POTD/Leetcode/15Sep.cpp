#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        string kVowels = "aeiou"; // Replacing string_view with string
        int ans = 0;
        int prefix = 0; // the binary prefix
        unordered_map<int, int> prefixToIndex{{0, -1}};

        for (int i = 0; i < s.length(); ++i)
        {
            size_t index = kVowels.find(s[i]); // Use size_t for index type
            if (index != string::npos)         // string::npos instead of -1
                prefix ^= 1 << index;
            if (prefixToIndex.find(prefix) == prefixToIndex.end()) // Use find instead of contains
                prefixToIndex[prefix] = i;
            ans = max(ans, i - prefixToIndex[prefix]);
        }

        return ans;
    }
};
