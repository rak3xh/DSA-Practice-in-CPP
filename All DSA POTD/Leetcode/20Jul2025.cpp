// C++ 14 Solution

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    unordered_map<string, shared_ptr<TrieNode>> children;
    bool deleted = false;
};

class Solution
{
public:
    Solution() : root(make_shared<TrieNode>()) {}

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        vector<vector<string>> ans;
        vector<string> path;
        unordered_map<string, vector<shared_ptr<TrieNode>>> subtreeToNodes;

        sort(paths.begin(), paths.end()); // Replaces ranges::sort

        for (const vector<string> &path : paths)
        {
            shared_ptr<TrieNode> node = root;
            for (const string &s : path)
            {
                if (node->children.find(s) == node->children.end())
                {
                    node->children[s] = make_shared<TrieNode>();
                }
                node = node->children[s];
            }
        }

        buildSubtreeToRoots(root, subtreeToNodes);

        for (auto it = subtreeToNodes.begin(); it != subtreeToNodes.end(); ++it)
        {
            const vector<shared_ptr<TrieNode>> &nodes = it->second;
            if (nodes.size() > 1)
            {
                for (shared_ptr<TrieNode> node : nodes)
                {
                    node->deleted = true;
                }
            }
        }

        constructPath(root, path, ans);
        return ans;
    }

private:
    shared_ptr<TrieNode> root;

    string buildSubtreeToRoots(
        shared_ptr<TrieNode> node,
        unordered_map<string, vector<shared_ptr<TrieNode>>> &subtreeToNodes)
    {

        vector<pair<string, shared_ptr<TrieNode>>> sortedChildren(
            node->children.begin(), node->children.end());
        sort(sortedChildren.begin(), sortedChildren.end());

        string subtree = "(";
        for (const auto &p : sortedChildren)
        {
            subtree += p.first + buildSubtreeToRoots(p.second, subtreeToNodes);
        }
        subtree += ")";

        if (subtree != "()")
            subtreeToNodes[subtree].push_back(node);

        return subtree;
    }

    void constructPath(shared_ptr<TrieNode> node, vector<string> &path,
                       vector<vector<string>> &ans)
    {
        for (auto it = node->children.begin(); it != node->children.end(); ++it)
        {
            const string &s = it->first;
            shared_ptr<TrieNode> child = it->second;
            if (!child->deleted)
            {
                path.push_back(s);
                constructPath(child, path, ans);
                path.pop_back();
            }
        }
        if (!path.empty())
            ans.push_back(path);
    }
};

// C+ 20 Solution
//  #include <bits/stdc++.h>
//  using namespace std;
//  struct TrieNode
//  {
//      unordered_map<string, shared_ptr<TrieNode>> children;
//      bool deleted = false;
//  };
//  class Solution
//  {
//  public:
//      vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
//      {
//          vector<vector<string>> ans;
//          vector<string> path;
//          unordered_map<string, vector<shared_ptr<TrieNode>>> subtreeToNodes;

//         ranges::sort(paths);

//         for (const vector<string> &path : paths)
//         {
//             shared_ptr<TrieNode> node = root;
//             for (const string &s : path)
//             {
//                 if (!node->children.contains(s))
//                     node->children[s] = make_shared<TrieNode>();
//                 node = node->children[s];
//             }
//         }

//         buildSubtreeToRoots(root, subtreeToNodes);

//         for (const auto &[_, nodes] : subtreeToNodes)
//             if (nodes.size() > 1)
//                 for (shared_ptr<TrieNode> node : nodes)
//                     node->deleted = true;

//         constructPath(root, path, ans);
//         return ans;
//     }

// private:
//     shared_ptr<TrieNode> root = make_shared<TrieNode>();

//     string buildSubtreeToRoots(
//         shared_ptr<TrieNode> node,
//         unordered_map<string, vector<shared_ptr<TrieNode>>> &subtreeToNodes)
//     {
//         string subtree = "(";
//         for (const auto &[s, child] : node->children)
//             subtree += s + buildSubtreeToRoots(child, subtreeToNodes);
//         subtree += ")";
//         if (subtree != "()")
//             subtreeToNodes[subtree].push_back(node);
//         return subtree;
//     }

//     void constructPath(shared_ptr<TrieNode> node, vector<string> &path,
//                        vector<vector<string>> &ans)
//     {
//         for (const auto &[s, child] : node->children)
//             if (!child->deleted)
//             {
//                 path.push_back(s);
//                 constructPath(child, path, ans);
//                 path.pop_back();
//             }
//         if (!path.empty())
//             ans.push_back(path);
//     }
// };