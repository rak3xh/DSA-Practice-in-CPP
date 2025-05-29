#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
private:
    void dfs(map<Node *, bool> &vis, int currentDepth, int currentSum, int &depth, int &ans, Node *node)
    {
        if (node->left == nullptr && node->right == nullptr && vis[node] == false)
        {
            currentSum += node->data;
            currentDepth++;
            if (currentDepth > depth)
            {
                depth = currentDepth;
                ans = currentSum;
            }
            else if (currentDepth == depth)
            {
                ans = max(ans, currentSum);
            }
            vis[node] = true;
        }

        if (node->left)
        {
            dfs(vis, currentDepth + 1, currentSum + node->data, depth, ans, node->left);
        }
        if (node->right)
        {
            dfs(vis, currentDepth + 1, currentSum + node->data, depth, ans, node->right);
        }
    }

public:
    int sumOfLongRootToLeafPath(Node *root)
    {
        // code here
        int ans = 0, depth = 0;
        map<Node *, bool> vis;
        dfs(vis, 0, 0, depth, ans, root);
        return ans;
    }
};