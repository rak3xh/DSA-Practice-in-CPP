#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
private:
    void preorder(TreeNode *root, string &s)
    {
        if (root == nullptr)
        {
            s += "n ";
            return;
        }

        s += to_string(root->val) + " ";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    TreeNode *preorder(queue<string> &q)
    {
        const string s = q.front();
        q.pop();
        if (s == "n")
            return nullptr;

        TreeNode *root = new TreeNode(stoi(s));
        root->left = preorder(q);
        root->right = preorder(q);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s;
        preorder(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream iss(data);
        queue<string> q;

        for (string s; iss >> s;)
            q.push(s);

        return preorder(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));