# [Number of islands](https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1)

### BFS solution

-   **TC: O(N\*M)**
-   **SC: O(N\*M) + O(N\*M)**, vis array and queue

```cpp
class Solution {
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col)
    {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({ row, col });

        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // traverse the neighbors
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nr = r + i; // new row
                    int nc = c + j; // new col
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && grid[nr][nc] == '1') {
                        vis[nr][nc] = 1;
                        q.push({ nr, nc });
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    bfs(grid, vis, i, j);
                }
            }
        }

        return cnt;
    }
};
```

### DFS solution

```cpp
class Solution {
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col)
    {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nr = row + i; // new row
                int nc = col + j; // new col
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && grid[nr][nc] == '1') {
                    vis[nr][nc] = 1;
                    dfs(grid, vis, nr, nc);
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, vis, i, j);
                }
            }
        }

        return cnt;
    }
};
```
