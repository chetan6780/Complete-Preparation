# Adjacency matrix representation of Graph

- Use matrix to represent a graph.
- Initialize it with 0s.
- Then take u and v , set adj[u][v] = 1 and adj[v][u] = 1.

1. First line contains n and m , n = number of nodes , m = number of edges
2. Next m lines contains edges between u and v.
3. In case of directed graph only push back once.

### Disadvantage

- We cannot create matrix greater than 10^5.

### Code

```cpp

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // declare the adjacent matrix
    int adj[n + 1][n + 1];

    // take edges as input
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}
```
