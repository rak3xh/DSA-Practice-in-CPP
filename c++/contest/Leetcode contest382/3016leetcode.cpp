#include <string.h>
#include <iostream>

using namespace std;
class Solution
{
public:
    int countKeyChanges(string s)
    {
        if (s.empty())
        {
            return 0;
        }

        int keyChanges = 0;
        char prevChar = std::tolower(s[0]); // Initialize with the lowercase version of the first character

        for (size_t i = 1; i < s.length(); ++i)
        {
            char currentChar = std::tolower(s[i]);
            if (currentChar != prevChar)
            {
                ++keyChanges;
                prevChar = currentChar;
            }
        }

        return keyChanges;
    }
};