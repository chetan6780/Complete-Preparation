# Adjacency list representation of Graph

Effecient than adjacency matrix representation of graph.

- Declare **Array of Vector<int>**.

1. First line contains n and m , n = number of nodes , m = number of edges
2. Next m lines contains edges between u and v.
3. In case of directed graph only push back once.
4. If they have weights , we take vector of pair, vector<pair<int, int>> and push back pair.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // declare the adjacent matrix
    vector<int> adj[n + 1];

    // take edges as input
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}

// For weights
int main()
{
    int n, m;
    cin >> n >> m;

    // declare the adjacent matrix
    vector<pair<int, int>> adj[n + 1];

    // take edges as input
    for (int i = 0; i < m; i++)
    {
        int u, v,wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    return 0;
}
```
