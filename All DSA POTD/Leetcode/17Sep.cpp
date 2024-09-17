#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        vector<string> ans;
        unordered_map<string, int> count;
        istringstream iss(s1 + ' ' + s2); // Combining both sentences with a space

        string word;
        while (iss >> word) // Read each word
            ++count[word];  // Increment the word count

        for (const auto &pair : count) // Iterate through the word frequency map
            if (pair.second == 1)      // If the word occurs only once, add it to the result
                ans.push_back(pair.first);

        return ans;
    }
};