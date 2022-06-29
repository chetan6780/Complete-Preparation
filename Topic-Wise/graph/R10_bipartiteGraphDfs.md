# Bipartite Graph DFS

- **Bipartite Graph** - A Graph that can be colored in two colors such that no two adjacent vertices are colored in the same color.

- If it has **_odd lenght cycle_** it is **_not bipartite graph_**,else it is bipartite graph.

### Examples:

**Bipartite graph example**

```
8 7
0 1
1 2
2 3
3 4
4 6
6 7
1 7
4 5
```

**Not bipartite example**

```
7 7
0 1
1 2
2 3
3 4
4 6
6 1
4 5
```

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

bool bipartiteDfs(int node, vector<int> adj[], int color[])
{
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (!bipartiteDfs(it, adj, color))
            {
                return false;
            }
        }
        else if (color[it] == color[node])
            return false;
    }
    return true;
}
bool checkBipartite(vector<int> adj[], int n)
{
    int color[n];
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            if (!bipartiteDfs(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (checkBipartite(adj, n))
    {
        cout << "yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}

```
