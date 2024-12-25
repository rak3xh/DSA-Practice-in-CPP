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
    vector<int> largestValues(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        vector<int> ans;
        queue<TreeNode *> q{{root}};

        while (!q.empty())
        {
            int mx = INT_MIN;
            for (int sz = q.size(); sz > 0; --sz)
            {
                TreeNode *node = q.front();
                q.pop();
                mx = max(mx, node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(mx);
        }

        return ans;
    }
};