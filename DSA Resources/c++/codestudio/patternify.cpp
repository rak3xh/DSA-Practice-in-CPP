/*
   Time complexity: O(N ^ 2)
   Space complexity: O(N ^ 2)

   Where N is the size of the pattern
*/
#include <bits/stdc++.h>
using namespace std;
vector<string> printPatt(int n)
{
    // Create an array of string for storing the pattern
    vector<string> answer;

    // Create a string that will contain 'N' '*' characters
    string str;

    for (int i = 0; i < n; i++)
    {
        // Append '*' in string in each iteration of loop
        str.push_back('*');
    }

    // Run a loop from 'i'=1 to 'i'='N'
    for (int i = 1; i <= n; i++)
    {
        // Append current string to answer
        answer.push_back(str);

        // Decrese length of string by 1
        str.pop_back();
    }

    // Return the array of string that contains pattern
    return answer;
}