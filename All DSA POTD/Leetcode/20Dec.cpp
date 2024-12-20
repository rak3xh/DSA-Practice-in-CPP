#include <bits/stdc++.h>
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
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        dfs(root->left, root->right, true);
        return root;
    }

private:
    void dfs(TreeNode *left, TreeNode *right, bool isOddLevel)
    {
        if (left == nullptr)
            return;
        if (isOddLevel)
            swap(left->val, right->val);
        dfs(left->left, right->right, !isOddLevel);
        dfs(left->right, right->left, !isOddLevel);
    }
};