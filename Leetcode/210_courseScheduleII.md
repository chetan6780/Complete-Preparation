# [210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) 🌟🌟

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

-   For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

### Topological Sort + DFS

-   Make adjacecncy list
-   Detect CYCLE...If present then return empty array
-   Find toposort and store it in stack
-   Apply DFS and find topological sort

### Code

```cpp
class Solution {
    // Graph coloring: 0->not visited...1->visited...2->visited & processed
    bool detectCycle_util(vector<vector<int>>& adj, vector<int>& visited, int v)
    {
        if (visited[v] == 1)
            return true;
        if (visited[v] == 2)
            return false;

        visited[v] = 1; // Mark current as visited
        for (int i = 0; i < adj[v].size(); ++i)
            if (detectCycle_util(adj, visited, adj[v][i]))
                return true;

        visited[v] = 2; // Mark current node as processed
        return false;
    }

    // Cycle detection
    bool detectCycle(vector<vector<int>>& adj, int n)
    {
        vector<int> visited(n, 0);
        for (int i = 0; i < n; ++i)
            if (!visited[i])
                if (detectCycle_util(adj, visited, i))
                    return true;
        return false;
    }

    // Topological sort
    void dfs(vector<vector<int>>& adj, int v, vector<bool>& visited, stack<int>& stk)
    {
        visited[v] = true;
        for (int i = 0; i < adj[v].size(); ++i)
            if (!visited[adj[v][i]])
                dfs(adj, adj[v][i], visited, stk);

        stk.push(v);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        // Make adjacecncy list
        for (int i = 0; i < n; ++i)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);

        // Detect CYCLE...If present then return empty array
        vector<int> ans;
        if (detectCycle(adj, numCourses))
            return ans;

        // Find toposort and store it in stack
        stack<int> stk;
        vector<bool> visited(numCourses, false);

        // Apply DFS and find topological sort
        for (int i = 0; i < numCourses; ++i)
            if (!visited[i])
                dfs(adj, i, visited, stk);

        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};
```

### READ

-   [✅ [C++/Python] Simple Solutions w/ Explanation | Topological Sort using BFS & DFS](https://leetcode.com/problems/course-schedule-ii/discuss/1642354/C%2B%2BPython-Simple-Solutions-w-Explanation-or-Topological-Sort-using-BFS-and-DFS)
