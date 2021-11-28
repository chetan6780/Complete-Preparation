# [797. All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target/) 🌟🌟

Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

### BFS

-   We can start from the starting node 0 and traverse every possible next node from the current node.
-   Whenever we reach the last node n-1, we will add the path till now into the final answer.

This process can be implemented using a BFS traversal as -

-   Initialize a queue of path of nodes with the node 0 inserted into it initially denoting the starting node in our traversal path from 0 to n-1
-   Pop an element path from the queue
-   Explore every child node of last node in the path. That is, we try every possible edge in graph from node at the end of current path. Each edge added to end of path gives us another path which will be added to queue for further exploration
-   If the last node in path is n-1, we know that this is a valid source to target path in the graph. So, we add it to final list of paths
-   We repeat this process until the queue is not empty, that is, until there are paths remaining to be explored.
-   **Time Complexity : O(2^N)**, where N is the number of nodes in the graph. Every node except the start and end node of graph can either be part of a path or not be part of a path. For a path consisting of k (`3 <= k <= n`) nodes, we have k-2 intermediate nodes and we can choose from n-2 available nodes. Thus the resulting time complexity is `Σ n-2Ck-2` for all `3 <= k <= n`, which comes out to be `O(2N-2) = O(2N)`
-   **Space Complexity : O(2^N)**

### Code

```cpp
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<vector<int>> ans;
        queue<vector<int>> q;

        q.push({ 0 }); // push the initial source
        while (q.size()) {
            auto path = move(q.front()); // efficiently copy (pointer copy)
            q.pop();

            if (path.back() == graph.size() - 1) // found valid path
                ans.push_back(move(path));
            else
                for (auto x : graph[path.back()]) { // try every possible next node in path
                    path.push_back(x);
                    q.push(path); // push path into queue for further exploration
                    path.pop_back();
                }
        }
        return ans;
    }
};
```

---

### DFS - Backtracking

-   We can also solve this problem using DFS traversal.
-   This traversal should also be more efficient in terms of space usage as compared to BFS traversal since we are only required to keep a single path in memory at a given time.
-   Note that we don't need to maintain a data structure such as seen to keep track of visited nodes since this is a DAG and thus no recursive dfs call will end up visiting same node twice.

The process of finding all paths using DFS can be implemented as -

-   Begin DFS traversal from the node 0
-   At each step of DFS, add the current node i to the path.
-   If the current node i in dfs call is n-1, we know that this is a valid source to target path in the graph. So, we add it to final list of paths.
-   Otherwise, we explore further path by trying each possible next nodes, that is, we recursively call DFS for every child node of i in the graph.
-   The above process continues till every possible path is tried out by dfs.

-   **Time Complexity : O(2^N)**, same as above
-   **Space Complexity : O(N)**, required by max recursive stack depth and for storing path. Generally output space is not considered towards overall space complexity.

### Code

```cpp
class Solution {
private:
    void dfs(int src, int dest, vector<vector<int>>& graph, vector<int>& curr, vector<vector<int>>& ans)
    {
        if (src == dest) { // base condition - found a path
            ans.push_back(curr);
            return;
        }
        for (int x : graph[src]) {
            curr.push_back(x); // DO
            dfs(x, dest, graph, curr, ans); // RECUR
            curr.pop_back(); // UNDO/Backtrack
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<vector<int>> ans;
        vector<int> curr;

        curr.push_back(0); // push the initial source
        dfs(0, graph.size() - 1, graph, curr, ans); // dfs(src,dest,graph,curr,ans)

        return ans;
    }
};
```
