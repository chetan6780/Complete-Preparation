# Breadth first search(BFS)

-   In Breath First Search, we start from a source vertex and explore all the vertices that are reachable from it.
-   We explore all the vertices at a particular level before going to the next level.

### Algorithm

-   Take visited array and initialize it with 0.
-   Size of visited array is N if graph is 0 based indexed and N+1 if graph is 1 based indexed.
-   Take a queue and push the source vertex in it. make `visited[0] = 1`.
-   While queue is not empty, pop the front element and store it in ans array.
-   Traverse all the adjacent vertices of the popped element and push them in the queue if they are not visited.
-   Set `visited[source]=1` for all the adjacent vertices.
-   Repeat the above steps until queue is empty.
-   Return ans array.
-   **SC: O(3\*N) = O(N)**
-   **TC: O(N)+O(2\*E)**, For directed graph.

### Code

```cpp
vector<int> bfs(int N, vector<int> adj[])
{
    vector<int> ans;
    vector<int> vis(N, 0);

    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    return ans;
}
```
