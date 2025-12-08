// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTriples(int n)
    {
        int ans = 0;
        unordered_set<int> squared;

        for (int i = 1; i <= n; ++i)
            squared.insert(i * i);

        for (const int a : squared)
            for (const int b : squared)
                if (squared.count(a + b)) // replaced contains() with count()
                    ++ans;

        return ans;
    }
};

// C++ 20 Solution
//  #include <bits/stdc++.h>
//  using namespace std;
//  class Solution
//  {
//  public:
//      int countTriples(int n)
//      {
//          int ans = 0;
//          unordered_set<int> squared;

//         for (int i = 1; i <= n; ++i)
//             squared.insert(i * i);

//         for (const int a : squared)
//             for (const int b : squared)
//                 if (squared.contains(a + b))
//                     ++ans;

//         return ans;
//     }
// };