#include <bits/stdc++.h>

using namespace std;

class Graph
{

public:
    int V;
    list<int> *adj;
};
bool isCyclicUtil(int v, bool visited[], int parent, list<int> *adj)

{

    visited[v] = true;

    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i)

    {

        if (!visited[*i])

        {

            if (isCyclicUtil(*i, visited, v, adj))

                return true;
        }

        else if (*i != parent)

            return true;
    }

    return false;
}

bool isCyclic(Graph g)

{

    bool *visited = new bool[g.V];

    for (int i = 0; i < g.V; i++)

        visited[i] = false;

    for (int u = 0; u < g.V; u++)

        if (!visited[u])

            if (isCyclicUtil(u, visited, -1, g.adj))

                return true;

    return false;
}
