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
// TC: Amortized O(1) [O(αN) - α is inverse ackermann function, we assume it constant]
```


### Leetcode Implementation

```cpp
class UnionFind {
private:
    vector<int> root;
    vector<int> rank;
    int count;

public:
    UnionFind(int sz) : root(sz), rank(sz), count(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }
    }

    int getCount() {
        return count;
    }

    bool isConnected(int u, int v) {
        return find(u) == find(v);
    }
};
```