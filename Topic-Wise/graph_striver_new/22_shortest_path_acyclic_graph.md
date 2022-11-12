# Shorted path in acyclic graph

-   [GFG](https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/)

### DFS Solution (toposort)

-   **TC: O(N+E)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
    void toposort(int node, vector<pair<int, int>> adj[], vector<int>& vis, stack<int>& st)
    {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it.first]) {
                toposort(it.first, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges)
    {
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++) { // till M - no. of edges
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({ v, wt });
        }

        // find the topo sort
        vector<int> vis(N, 0);
        stack<int> st;
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                toposort(i, adj, vis, st);
            }
        }

        // find the shortest distance
        vector<int> dist(N, 1e9);
        dist[0] = 0; // source node have distance 0
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }
        return dist;
    }
};
```
