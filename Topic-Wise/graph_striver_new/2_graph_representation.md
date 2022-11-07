# Graph Representation

There are 2 representations of the graph.

1. Adjacency Matrix
2. Adjacency List

**1. Adjacency Matrix:**

```cpp
int main()
{
    int n, m;
    cin >> n >> m;

    // Graph Adjacency Matrix Space: O(N*N)
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}
```

-   **Note:** If the graph is directed, then we will not make `adj[v][u] = 1`.
-   **Note:** If the graph is weighted, then we will not make `adj[u][v] = 1` and `adj[v][u] = 1` but `adj[u][v] = w` and `adj[v][u] = w`.

**2. Adjacency List:**

```cpp
int main()
{
    int n, m;
    cin >> n >> m;

    // Graph Adjacency List Space: O(2*E)
    vector<int> adj[n + 1]; // Array of vectors not vector of arrays
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}
```

-   **Note:** If the graph is directed, then we will not push `v` into `adj[u]`.
-   **Note:** If the graph is weighted, then we will not push `v` into `adj[u]` but `adj[u].push_back({v, w})`. We will use **pair** to store the weight.
