#include <bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
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
    string smallestFromLeaf(TreeNode *root)
    {
        string ans;
        dfs(root, "", ans);
        return ans;
    }

private:
    void dfs(TreeNode *root, string &&path, string &ans)
    {
        if (root == nullptr)
            return;

        path.push_back(root->val + 'a');

        if (root->left == nullptr && root->right == nullptr)
        {
            reverse(path.begin(), path.end());
            if (ans == "" || ans > path)
                ans = path;
            reverse(path.begin(), path.end()); // Roll back.
        }

        dfs(root->left, move(path), ans);
        dfs(root->right, move(path), ans);
        path.pop_back();
    }
};