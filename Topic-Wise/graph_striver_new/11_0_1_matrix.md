# 0 1 matrix

-   [GFG](https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1)
-   [Leetcode](https://leetcode.com/problems/01-matrix/)

### BFS

-   **TC: O(N\*M)**
-   **SC: O(N\*M)**

### Code

```cpp
class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        // pair of (i, j) and distance
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({ { i, j }, 0 });
                    vis[i][j] = 1;
                }
            }
        }

        vector<pair<int, int>> dirs = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            for (auto dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    dist[nr][nc] = steps + 1;
                    q.push({ { nr, nc }, steps + 1 });
                }
            }
        }
        return dist;
    }
};
```
