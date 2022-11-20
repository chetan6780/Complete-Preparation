# Bipartite graph

-   **Bipartite graph:** A graph is bipartite if it can be colored using **two colors** such that **no two adjacent vertices/nodes** have the **same color**.
-   Linear graph with no cycle are always bipartite.
-   Any graph with **even length cycle** is bipartite.
-   Any graph with **odd length cycle** is not bipartite.

-   [GFG](https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)
-   [Leetcode](https://leetcode.com/problems/is-graph-bipartite/description/)

### Bipartite graph using BFS

```cpp
class Solution {
    bool check(int start, int V, vector<int> adj[], vector<int>& color)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (color[it] == -1) {
                    color[it] = 1 - color[node];
                    q.push(it);
                } else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (check(i, V, adj, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

### DFS

```cpp
class Solution {
    bool dfs(int node, int clr, vector<int>& color, vector<int> adj[])
    {
        color[node] = clr;
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                if (dfs(it, 1 - clr, color, adj) == false) {
                    return false;
                }
            } else if (color[it] == color[node]) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, adj) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};
```
