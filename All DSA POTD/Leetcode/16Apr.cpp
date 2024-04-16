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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        int d = 0;
        queue<TreeNode *> q{{root}};

        while (!q.empty())
        {
            ++d;
            for (int sz = q.size(); sz > 0; --sz)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                if (d == depth - 1)
                {
                    TreeNode *cachedLeft = node->left;
                    TreeNode *cachedRight = node->right;
                    node->left = new TreeNode(val);
                    node->right = new TreeNode(val);
                    node->left->left = cachedLeft;
                    node->right->right = cachedRight;
                }
            }
            if (d == depth - 1)
                break;
        }

        return root;
    }
};