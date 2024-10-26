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
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        vector<int> ans;

        dfs(root, 0, 0);

        for (const int query : queries)
            ans.push_back(valToMaxHeight[query]);

        return ans;
    }

private:
    // valToMaxHeight[val] := the maximum height without the node with `val`
    unordered_map<int, int> valToMaxHeight;
    // valToHeight[val] := the height of the node with `val`
    unordered_map<int, int> valToHeight;

    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        auto it = valToHeight.find(root->val); // Declare `it` separately
        if (it != valToHeight.cend())          // Check the condition
            return it->second;
        return valToHeight[root->val] = 1 + max(height(root->left), height(root->right));
    }

    // maxHeight := the maximum height without the current node `root`
    void dfs(TreeNode *root, int depth, int maxHeight)
    {
        if (root == nullptr)
            return;
        valToMaxHeight[root->val] = maxHeight;
        dfs(root->left, depth + 1, max(maxHeight, depth + height(root->right)));
        dfs(root->right, depth + 1, max(maxHeight, depth + height(root->left)));
    }
};