#include <iostream>
#include <utility>   // For std::pair
#include <algorithm> // For std::min and std::max
#include <climits>   // For INT_MAX and INT_MIN

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int ans = 0;
    pair<int, int> dfs(TreeNode *root)
    {
        if (!root)
            return {INT_MAX, INT_MIN};
        pair<int, int> leftMinMax = dfs(root->left);
        pair<int, int> rightMinMax = dfs(root->right);
        int lmin = leftMinMax.first, lmax = leftMinMax.second;
        int rmin = rightMinMax.first, rmax = rightMinMax.second;
        int mn = min({root->val, lmin, rmin}), mx = max({root->val, lmax, rmax});
        ans = max({ans, abs(root->val - mn), abs(mx - root->val)});
        return {mn, mx};
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};
