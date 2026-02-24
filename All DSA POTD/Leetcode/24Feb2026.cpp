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
    int sumRootToLeaf(TreeNode *root)
    {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }

private:
    void dfs(TreeNode *root, int val, int &ans)
    {
        if (root == nullptr)
            return;
        val = val * 2 + root->val;
        if (root->left == nullptr && root->right == nullptr)
            ans += val;
        dfs(root->left, val, ans);
        dfs(root->right, val, ans);
    }
};