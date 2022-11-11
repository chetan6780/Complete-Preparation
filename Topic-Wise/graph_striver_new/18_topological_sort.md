# Topological Sort

-   **Topological sort** is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering.
-   Topological Sorting for a graph is only possible if the graph is a **DAG**.
-   **It's just normal DFS but we need to store the vertices in a stack in the order of their finishing time.**
-   BFS version of topological sort is called **Kahn's algorithm**, we see it in next part.
-   **TC: O(V+E)**
-   **SC: O(V)**

### Code

```cpp

class Solution {
    void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st)
    {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};
```
