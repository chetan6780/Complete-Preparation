# Depth first search(DFS)

-   We traverse the graph in depth wise manner.
-   We use recursion for DFS.

### Algorithm

-   Take visited array and initialize it with 0.
-   Size of visited array is N if graph is 1 based indexed and N+1 if graph is 0 based indexed.
-   We use recursive function dfs to traverse the graph.
-   In dfs function, we push the current node in ans array and set `visited[node]=1`.
-   We traverse all the adjacent vertices of the current node and call dfs function for them if they are not visited.
-   Repeat the above steps until all the nodes are visited.
-   Return ans array.
-   **SC: O(N)**
-   **TC: O(N)+O(2\*E)**, For directed graph.

```cpp
void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& ans)
{
    vis[node] = 1;
    ans.push_back(node);
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis, ans);
        }
    }
}
vector<int> dfsOfGraph(int N, vector<int> adj[])
{
    vector<int> ans;
    vector<int> vis(N, 0);
    int start = 0;
    dfs(start, adj, vis, ans);
    return ans;
}
```
