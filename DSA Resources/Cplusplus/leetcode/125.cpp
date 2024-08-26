#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        return checkPalindrome(s, 0, s.length() - 1);
    }

private:
    bool checkPalindrome(const string &s, int left, int right)
    {
        // Base case: If pointers have crossed each other, it is a palindrome
        if (left >= right)
            return true;

        // Move left pointer to the next alphanumeric character
        if (!isalnum(s[left]))
        {
            return checkPalindrome(s, left + 1, right);
        }

        // Move right pointer to the previous alphanumeric character
        if (!isalnum(s[right]))
        {
            return checkPalindrome(s, left, right - 1);
        }

        // Compare characters (ignoring case)
        if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }

        // Recur for the next pair of characters
        return checkPalindrome(s, left + 1, right - 1);
    }
};