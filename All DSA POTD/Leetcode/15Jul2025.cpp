// C++ 14 Solution
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution
{
public:
    bool isValid(string word)
    {
        if (word.length() < 3)
            return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char c : word)
        {
            if (!isalnum(c))
                return false;

            if (isVowel(c))
                hasVowel = true;
            else if (isConsonant(c))
                hasConsonant = true;
        }

        return hasVowel && hasConsonant;
    }

private:
    bool isVowel(char c)
    {
        char lower = tolower(c);
        return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
    }

    bool isConsonant(char c)
    {
        return isalpha(c) && !isVowel(c);
    }
};

// C++ 20 Solution
//  #include <bits/stdc++.h>
//  using namespace std;
//  class Solution
//  {
//  public:
//      bool isValid(string word)
//      {
//          return word.length() >= 3 &&
//                 ranges::all_of(word, [](char c)
//                                { return isalnum(c); }) &&
//                 ranges::any_of(word, isVowel) && ranges::any_of(word, isConsonant);
//      }

// private:
//     static bool isVowel(char c)
//     {
//         static constexpr string_view kVowels = "aeiouAEIOU";
//         return kVowels.find(c) != string_view::npos;
//     }

//     static bool isConsonant(char c)
//     {
//         return isalpha(c) && !isVowel(c);
//     }
// };