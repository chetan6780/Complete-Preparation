# [310. Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/) 🌟🌟

A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h)) are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

### Topological Sort

<!-- ! Explanation here -->

```cpp
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0), ans; // vector<int> indegree keeps count of the number of nodes approaching a node

        for (auto& e : edges) { // Creating an adjacency matrix for the given graph
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1)
                q.push(i), indegree[i]--; // add all the leaf nodes to the queue
        }

        while (!q.empty()) {
            int s = q.size();
            ans.clear();
            for (int i = 0; i < s; i++) {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for (auto child : graph[curr]) { // For each node, attached to the leaf niodes, we decrement the indegree i.e remove the leaf nodes connected to them. We keep on doing this until we reach the middle nodes.
                    indegree[child]--;
                    if (indegree[child] == 1)
                        q.push(child);
                }
            }
        }
        if (n == 1)
            ans.push_back(0); // If there is only 1 node in the graph, the min height is 0, with root being '0'
        return ans;
    }
};
```

### MUST READ

-   [Share some thought](https://leetcode.com/problems/minimum-height-trees/discuss/76055/Share-some-thoughts)
-   [[C++] Simple Solution | Topological Sort | W/ Explanation (above solution)](https://leetcode.com/problems/minimum-height-trees/discuss/1630778/C%2B%2B-Simple-Solution-or-Topological-Sort-or-W-Explanation)
