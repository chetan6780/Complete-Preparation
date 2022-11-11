# Eventual Safe States

-   [GFG](https://practice.geeksforgeeks.org/problems/eventual-safe-states/1)
-   [Leetcode](https://leetcode.com/problems/find-eventual-safe-states/)

-   Any node which is part of cycle is not safe.
-   Any node that leads to cycle is not safe.
-   Every other node is safe.

### Detect cycle in directed graph (DFS)

-   We can do this in single array, mark visited as `1` , path visited as `2` and safe node as `3`, but its not required.
-   Below is approach with 3 arrays.
-   **TC: O(V+E)**
-   **SC: O(V)**

### Code

```cpp
class Solution {
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int>& check)
    {
        // mark both as visited
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis, check))
                    return true;
            } else if (pathVis[it]) {
                // its visited and also visited in path as well
                return true;
            }
        }
        pathVis[node] = 0;
        check[node] = 1; // new added line in detect cycle code
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> safeNode;
        vector<int> check(V, 0);
        vector<int> vis(V, 0), pathVis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, pathVis, check);
            }
        }
        for (int i = 0; i < V; i++) {
            if (check[i])
                safeNode.push_back(i);
        }
        return safeNode;
    }
};
```

### BFS

-   Prerequisite: [Topological Sort](./18_topological_sort.md)
-   **TC: O(V+E)**
-   **SC: O(V)**

### Code

```cpp

class Solution {
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> adjRev[V];
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNode;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                safeNode.push_back(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adjRev[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it);
                    safeNode.push_back(it);
                }
            }
        }

        sort(safeNode.begin(), safeNode.end());
        return safeNode;
    }
};
```
