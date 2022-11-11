# Detect cycle in undirected graph

-   [GFG](https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)
-   [Leetcode](https://leetcode.com/problems/number-of-provinces/)

### BFS solution

-   **TC: O(N+2\*E) + O(N)**
-   **SC: O(N) + O(N)**

```cpp
class Solution {
    bool detect(int src, vector<int> adj[], vector<int>& vis)
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src,-1});
        while (!q.empty()) {
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();

            for (auto adjNode : adj[node]) {
                if (!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push({ adjNode, node });
                } else if (vis[adjNode] && adjNode != prev) {
                    // if node is visited but its not previous node
                    // that means its visited by another node hence its a cycle.
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, adj, vis))
                    return true;
            }
        }
        return false;
    }
};
```

### DFS Solution

```cpp
class Solution {
    bool dfs(int node, int prev, vector<int> adj[], vector<int>& vis)
    {
        vis[node] = 1;
        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                if (dfs(adjNode, node, adj, vis))
                    return true;
            }else if(vis[adjNode] && adjNode != prev)
                return true;
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis))
                    return true;
            }
        }
        return false;
    }
};
```
