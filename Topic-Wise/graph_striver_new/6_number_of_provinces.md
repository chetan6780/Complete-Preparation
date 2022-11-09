# [Number of provinces](https://practice.geeksforgeeks.org/problems/number-of-provinces/1)

### BFS solution

-   **TC: O(N)+O(V+2\*E)**
-   **SC: O(N)+O(N)**

```cpp
class Solution {
    void dfs(int node, vector<int> adjList[], vector<int>& vis){
        vis[node] = 1;
        for (auto it : adjList[node]) {
            if (!vis[it]) {
                dfs(it, adjList, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V){
        // convert adj matrix to adj list
        vector<int> adjList[V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adjList, vis);
            }
        }
        return cnt;
    }
};
```
