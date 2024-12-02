#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        istringstream ss(sentence);
        string word;
        int index = 0;

        while (ss >> word)
        {
            index++;
            if (word.find(searchWord) == 0)
            { // Check if searchWord is a prefix
                return index;
            }
        }

        return -1;
    }
};