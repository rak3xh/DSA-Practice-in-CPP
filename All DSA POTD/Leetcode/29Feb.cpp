#include <bits/stdc++.h>
#include <queue>
using namespace std;
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
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> q{{root}};
        bool isEven = true;

        for (; !q.empty(); isEven = !isEven)
        {
            int prevVal = isEven ? INT_MIN : INT_MAX;
            for (int sz = q.size(); sz > 0; --sz)
            {
                TreeNode *node = q.front();
                q.pop();
                if (isEven && (node->val % 2 == 0 || node->val <= prevVal))
                    return false; // invalid case on even level
                if (!isEven && (node->val % 2 == 1 || node->val >= prevVal))
                    return false; // invalid case on odd level
                prevVal = node->val;
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
        }

        return true;
    }
};