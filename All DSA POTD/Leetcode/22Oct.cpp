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
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        vector<long> levelSums;
        dfs(root, 0, levelSums);
        if (levelSums.size() < k)
            return -1;

        nth_element(levelSums.begin(), levelSums.begin() + k - 1, levelSums.end(),
                    greater<>());
        return levelSums[k - 1];
    }

private:
    void dfs(TreeNode *root, int level, vector<long> &levelSums)
    {
        if (root == nullptr)
            return;
        if (levelSums.size() == level)
            levelSums.push_back(0);
        levelSums[level] += root->val;
        dfs(root->left, level + 1, levelSums);
        dfs(root->right, level + 1, levelSums);
    }
};