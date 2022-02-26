# [547. Number of Provinces](https://leetcode.com/problems/number-of-provinces/) 🌟🌟

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

### DSU implementation

-   We have to simply connect the components in DSU and return the connected component count.

### Code-1

```cpp
class UnionFind {
private:
    int n;
    int* parent;
    int* nodeRank;
    int connectedCount;

public:
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

    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // path compression
    }

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

    bool connected(int u, int v)
    {
        return findParent(u) == findParent(v);
    }

    int getConnectedCount()
    {
        return connectedCount;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        if (n == 0)
            return 0;
        UnionFind uf(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j])
                    uf.unionSet(i, j);
            }
        }

        return uf.getConnectedCount();
    }
};
```

### Code-2

-   leetcode solution

```cpp
class UnionFind {
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

private:
    vector<int> root;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.size() == 0) {
            return 0;
        }
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    uf.unionSet(i, j);
                }
            }
        }
        return uf.getCount();
    }
};
```
