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
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        unordered_map<int, int> postToIndex;

        for (int i = 0; i < postorder.size(); ++i)
            postToIndex[postorder[i]] = i;

        return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1, postToIndex);
    }

private:
    TreeNode *build(const vector<int> &preorder, int preStart, int preEnd,
                    const vector<int> &postorder, int postStart, int postEnd,
                    const unordered_map<int, int> &postToIndex)
    {
        if (preStart > preEnd)
            return nullptr;
        if (preStart == preEnd)
            return new TreeNode(preorder[preStart]);

        const int rootVal = preorder[preStart];
        const int leftRootVal = preorder[preStart + 1];
        const int leftRootPostIndex = postToIndex.at(leftRootVal);
        const int leftSize = leftRootPostIndex - postStart + 1;

        TreeNode *root = new TreeNode(rootVal);
        root->left = build(preorder, preStart + 1, preStart + leftSize, postorder, postStart,
                           leftRootPostIndex, postToIndex);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, postorder,
                            leftRootPostIndex + 1, postEnd - 1, postToIndex);
        return root;
    }
};