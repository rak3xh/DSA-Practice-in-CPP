// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        vector<string> ans;
        unordered_set<string> suppliesSet(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> inDegrees;
        queue<string> q;

        // Build the graph.
        for (size_t i = 0; i < recipes.size(); ++i)
        {
            for (const string &ingredient : ingredients[i])
            {
                if (suppliesSet.find(ingredient) == suppliesSet.end()) // Use find instead of contains
                {
                    graph[ingredient].push_back(recipes[i]);
                    ++inDegrees[recipes[i]];
                }
            }
        }

        // Perform topological sorting.
        for (const string &recipe : recipes)
        {
            if (inDegrees.find(recipe) == inDegrees.end()) // Use find instead of contains
            {
                q.push(recipe);
            }
        }

        while (!q.empty())
        {
            string u = q.front();
            q.pop();
            ans.push_back(u);

            if (graph.find(u) == graph.end()) // Use find instead of contains
                continue;

            for (const string &v : graph[u])
            {
                if (--inDegrees[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        return ans;
    }
};

// C++ 20 Solution
/*
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        vector<string> ans;
        unordered_set<string> suppliesSet(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> inDegrees;
        queue<string> q;

        // Build the graph.
        for (int i = 0; i < recipes.size(); ++i)
        for (const string &ingredient : ingredients[i])
        if (!suppliesSet.contains(ingredient))
        {
            graph[ingredient].push_back(recipes[i]);
            ++inDegrees[recipes[i]];
        }

        // Perform topological sorting.
        for (const string &recipe : recipes)
        if (!inDegrees.contains(recipe))
        q.push(recipe);

        while (!q.empty())
        {
            const string u = q.front();
            q.pop();
            ans.push_back(u);
            if (!graph.contains(u))
            continue;
            for (const string &v : graph[u])
            if (--inDegrees[v] == 0)
            q.push(v);
        }

        return ans;
    }
};
*/