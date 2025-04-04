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

struct T
{
    TreeNode *lca;
    int depth;
};

class Solution
{
public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        return dfs(root).lca;
    }

private:
    T dfs(TreeNode *root)
    {
        if (root == nullptr)
            return {nullptr, 0};
        const T left = dfs(root->left);
        const T right = dfs(root->right);
        if (left.depth > right.depth)
            return {left.lca, left.depth + 1};
        if (left.depth < right.depth)
            return {right.lca, right.depth + 1};
        return {root, left.depth + 1};
    }
};