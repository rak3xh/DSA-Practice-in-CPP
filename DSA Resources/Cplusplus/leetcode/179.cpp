// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        for (int step = 1; !q.empty(); ++step)
        {
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                string word = q.front();
                q.pop();

                for (int j = 0; j < word.length(); ++j)
                {
                    char cache = word[j];
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        word[j] = c;
                        if (word == endWord)
                            return step + 1;
                        if (wordSet.find(word) != wordSet.end())
                        {
                            q.push(word);
                            wordSet.erase(word);
                        }
                    }
                    word[j] = cache;
                }
            }
        }

        return 0;
    }
};

// C++ 20 Solution
/*
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.contains(endWord))
        return 0;

        queue<string> q{{beginWord}};

        for (int step = 1; !q.empty(); ++step)
        for (int sz = q.size(); sz > 0; --sz)
        {
            string word = q.front();
            q.pop();
            for (int i = 0; i < word.length(); ++i)
            {
                const char cache = word[i];
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    word[i] = c;
                    if (word == endWord)
                    return step + 1;
                    if (wordSet.contains(word))
                    {
                        q.push(word);
                        wordSet.erase(word);
                    }
                }
                word[i] = cache;
            }
        }

        return 0;
    }
};
*/