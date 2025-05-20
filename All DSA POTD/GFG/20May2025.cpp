#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    void dfs(Node *node, Node *par, map<Node *, Node *> &parent, int target, Node *&startNode)
    {
        if (node == NULL)
            return;
        parent[node] = par;
        if (node->data == target)
            startNode = node;
        dfs(node->left, node, parent, target, startNode);
        dfs(node->right, node, parent, target, startNode);
    }
    void dfs2(Node *node, Node *par, int time, int &totalTime, map<Node *, Node *> &parent)
    {
        if (node == NULL)
            return;
        totalTime = max(totalTime, time);
        if (node->left != par)
            dfs2(node->left, node, time + 1, totalTime, parent);
        if (node->right != par)
            dfs2(node->right, node, time + 1, totalTime, parent);
        if (parent.find(node) != parent.end() && parent[node] != par)
            dfs2(parent[node], node, time + 1, totalTime, parent);
    }
    int minTime(Node *root, int target)
    {
        // code here
        map<Node *, Node *> parent;
        Node *startNode = nullptr;
        dfs(root, NULL, parent, target, startNode); // O(V+E)
        int totalTime = 0;
        dfs2(startNode, NULL, 0, totalTime, parent); // O(V+E)
        return totalTime;
    }
};