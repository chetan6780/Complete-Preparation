# Course Schedule I & II

-   [GFG](https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1)
-   [GFG II](https://practice.geeksforgeeks.org/problems/course-schedule/1)
-   [Leetcode](https://leetcode.com/problems/course-schedule/)
-   [Leetcode II](https://leetcode.com/problems/course-schedule-ii/)

### Solution

-   After reading the problem statement we can solve this problem by two methods.
    -   **DFS - Detect a cycle in the graph**, if cycle present then return false else return true.
    -   **BFS - Topological sort**, if the number of nodes in the topological sort is equal to the number of nodes in the graph then **cycle is not present return true**, else cycle is present return false.
-   We solve it with BFS as in course schedule II we need to return the order of the courses.

### Code

```cpp
class Solution {
public:
    bool isPossible(int V, vector<pair<int, int>>& prerequisites)
    {
        vector<int> adj[V];
        for (auto it : prerequisites) {
            adj[it.first].push_back(it.second);
        }

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

        return topo.size() == V;
    }
};
```

### Course Schedule II

### Solution

```cpp
class Solution {
public:
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites)
    {
        vector<int> adj[V];
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); // here relationship is reverse of course schedule 1
        }

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

        if (topo.size() == V)
            return topo;
        return {};
    }
};
```
