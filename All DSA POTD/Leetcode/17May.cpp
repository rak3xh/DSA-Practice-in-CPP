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
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        if (root == nullptr)
            return nullptr;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        return isLeaf(root) && root->val == target ? nullptr : root;
    }

private:
    bool isLeaf(TreeNode *root)
    {
        return root->left == nullptr && root->right == nullptr;
    }
};