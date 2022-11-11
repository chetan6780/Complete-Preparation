# Number of distinct islands

-   [GFG](https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1)
-   [Leetcode Premium](https://leetcode.com/problems/number-of-distinct-islands/)

### DFS

-   **TC: O(N\*M)**
-   **SC: O(N\*M)**

### Code

```cpp
class Solution {
    vector<pair<int, int>> dirs = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c, int baseR, int baseC, vector<pair<int, int>>& v)
    {
        int n = grid.size(), m = grid[0].size();

        vis[r][c] = 1;
        v.push_back({ r - baseR, c - baseC });

        for (auto dir : dirs) {
            int nr = r + dir.first;
            int nc = c + dir.second;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1) {
                dfs(grid, vis, nr, nc, baseR, baseC, v);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> v;
                    dfs(grid, vis, i, j, i, j, v);
                    st.insert(v);
                }
            }
        }

        return st.size();
    }
};
```
