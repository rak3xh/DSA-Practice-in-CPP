#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans{};
        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(nums[i] * nums[i]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
} obj;
int main()
{
    vector<int> vec{5, 4, 3, 2, 1};
    vector<int> ans = obj.sortedSquares(vec);
    for (auto i = ans.begin(); i < ans.end(); i++)
    {
        cout << " " << *i;
    }
}