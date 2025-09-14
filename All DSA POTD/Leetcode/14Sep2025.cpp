#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        vector<string> ans;
        unordered_map<string, string> dict;

        for (const string &word : wordlist)
        {
            dict.insert({word, word});
            dict.insert({lowerKey(word), word});
            dict.insert({vowelKey(word), word});
        }

        for (const string &query : queries)
        {
            auto it = dict.find(query);
            if (it != dict.end())
            {
                ans.push_back(it->second);
            }
            else
            {
                it = dict.find(lowerKey(query));
                if (it != dict.end())
                {
                    ans.push_back(it->second);
                }
                else
                {
                    it = dict.find(vowelKey(query));
                    if (it != dict.end())
                    {
                        ans.push_back(it->second);
                    }
                    else
                    {
                        ans.push_back("");
                    }
                }
            }
        }

        return ans;
    }

private:
    string lowerKey(const string &word)
    {
        string s = "$"; // prefix to distinguish from vowelKey
        for (char c : word)
            s += static_cast<char>(tolower(c));
        return s;
    }

    string vowelKey(const string &word)
    {
        string s;
        for (char c : word)
            s += isVowel(c) ? '*' : static_cast<char>(tolower(c));
        return s;
    }

    bool isVowel(char c)
    {
        static const string kVowels = "aeiouAEIOU";
        return kVowels.find(c) != string::npos;
    }
};