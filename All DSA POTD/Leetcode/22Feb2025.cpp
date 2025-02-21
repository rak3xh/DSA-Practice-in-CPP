
// C++ 20 Solution
/*
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

class FindElements
{
    public:
    FindElements(TreeNode *root)
    {
        dfs(root, 0);
    }

    bool find(int target)
    {
        return vals.contains(target);
    }

    private:
    unordered_set<int> vals;

    void dfs(TreeNode *root, int val)
    {
        if (root == nullptr)
        return;

        root->val = val;
        vals.insert(val);
        dfs(root->left, val * 2 + 1);
        dfs(root->right, val * 2 + 2);
    }
};
*/

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */