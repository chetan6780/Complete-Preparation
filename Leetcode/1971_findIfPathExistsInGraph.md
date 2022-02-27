# [1971. Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/) 🌟

There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

### DFS

-   Basic DFS with stack

### Code

```cpp

class Solution {

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<vector<int>> adj_list(n);
        for (auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        stack<int> st;
        st.push(source);

        vector<bool> visited(n, false);

        while (!st.empty()) {
            int curr = st.top();
            st.pop();

            if (curr == destination) {
                return true;
            }

            for (auto& next : adj_list[curr]) {
                if (!visited[next]) {
                    visited[next] = true;
                    st.push(next);
                }
            }
        }
        return false;
    }
};
```

### UnionFind

-   If path exist between 2 nodes then they are in same component.
-   We can use UnionFind to know if source and destination are in same component.

### Code

```cpp

class UnionFind {
private:
    int* parent;
    int* nodeRank;
    int n;
    int connectedCount;

public:
    // TC: O(N)
    UnionFind(int sz)
    {
        this->n = sz;
        this->connectedCount = sz;
        parent = new int[n + 1];
        nodeRank = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            nodeRank[i] = 0;
        }
    }

    // TC: O(1) amortized
    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // path compression
    }

    // TC: O(1) amortized
    void unionSet(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);

        // union by rank
        if (u != v) {
            if (nodeRank[u] < nodeRank[v])
                parent[u] = v;
            else if (nodeRank[u] > nodeRank[v])
                parent[v] = u;
            else {
                parent[v] = u; // join to anyone
                nodeRank[u]++; // increase rank(level)
            }
            connectedCount--;
        }
    }

    // TC: O(1) amortized
    bool connected(int u, int v)
    {
        return findParent(u) == findParent(v);
    }

    // TC: O(1)
    int getConnectedCount()
    {
        return connectedCount;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        UnionFind uf(n);
        for (auto& edge : edges) {
            uf.unionSet(edge[0], edge[1]);
        }
        return uf.connected(source, destination);
    }
};

```
