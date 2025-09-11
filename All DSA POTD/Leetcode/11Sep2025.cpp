// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string sortVowels(string s)
    {
        string ans;
        vector<char> vowels;

        // Collect vowels
        for (char c : s)
        {
            if (isVowel(c))
                vowels.push_back(c);
        }

        // Sort vowels
        sort(vowels.begin(), vowels.end());

        // Replace vowels in original order
        int i = 0;
        for (char c : s)
        {
            if (isVowel(c))
                ans += vowels[i++];
            else
                ans += c;
        }

        return ans;
    }

private:
    bool isVowel(char c)
    {
        static const string kVowels = "aeiouAEIOU";
        return kVowels.find(c) != string::npos;
    }
};

//  C++ 20 Solution
//   #include <bits/stdc++.h>
//   using namespace std;
//   class Solution
//   {
//   public:
//       string sortVowels(string s)
//       {
//           string ans;
//           vector<char> vowels;

//         for (const char c : s)
//             if (isVowel(c))
//                 vowels.push_back(c);

//         ranges::sort(vowels);

//         int i = 0; // vowels' index
//         for (const char c : s)
//             ans += isVowel(c) ? vowels[i++] : c;

//         return ans;
//     }

// private:
//     bool isVowel(char c)
//     {
//         static constexpr string_view kVowels = "aeiouAEIOU";
//         return kVowels.find(c) != string_view::npos;
//     }
// };