### Disjoint Set Union (Union Find)

-   Following is the implementation of Disjoint Set Union data structure with path compression and union by rank which provides best time complexity `~O(1)` for both find and union operations.
-   Without path compression and union by rank, TC will be `O(logN)` OR `O(N)` depending on method used to create DSU class.

### Implementation

```cpp
// UnionFind class (DSU)
class UnionFind {
private:
    int* parent;
    int* nodeRank;
    int n;

public:
    // TC: O(N)
    UnionFind(int sz)
    {
        this->n = sz;
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
        if (nodeRank[u] < nodeRank[v])
            parent[u] = v;
        else if (nodeRank[u] > nodeRank[v])
            parent[v] = u;
        else {
            parent[v] = u; // join to anyone
            nodeRank[u]++; // increase rank(level)
        }
    }

    // TC: O(1) amortized
    bool connected(int u, int v)
    {
        return findParent(u) == findParent(v);
    }
};
// TC: Amortized O(1) [O(αN) - α is inverse ackermann function, we assume it constant]
```
