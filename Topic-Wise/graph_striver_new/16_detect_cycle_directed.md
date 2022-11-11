# Detect cycle in directed graph

### DFS

-   Normal dfs with single `visited` array will not work here as the node can be visited by other node but it is not in visited in the path of current node, in that case `visited` array will give us `true`(it is visited), and we declare it as cycle which is wrong.
-   To resolve above issue we use `visited` and `path visited` array so although the node is visited by other node but it is not visited in the path of current node, so we will have `false`(it is not visited), we declare it as not a cycle.
-   when both `visited` and `path visited` array will give us `true` then and then only we can say it is the cycle.
-   We can also use single `visited` array, mark visited as `1` and path visited as `2`.
-   **TC: O(V+E)**
-   **SC: O(V)**

### Code

```cpp
class Solution {
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis)
    {
        // mark both as visited
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis))
                    return true;
            } else if (pathVis[it]) {
                // its visited and also visited in path as well
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0), pathVis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis)) {
                    return true;
                }
            }
        }
        return false;
    }
};
```
