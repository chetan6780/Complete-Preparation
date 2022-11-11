# Kahn's algorithm

-   **Kahn's algorithm** is a BFS based algorithm for finding the topological sorting of a DAG.
-   It uses a queue to keep track of the vertices whose in-degree is 0.
-   **TC: O(V+E)**
-   **SC: O(V)**

### Code

```cpp
class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);
            // node in topo so decrease it from indegree
            for (auto it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo;
    }
};
```
