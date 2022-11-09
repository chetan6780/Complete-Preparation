# Rotten oranges

-   [GFG](https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1)
-   [leetcode](https://leetcode.com/problems/rotting-oranges/)

### BFS solution

-   **TC: O(N\*M)**
-   **SC: O(N\*M)**

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // {r,c},time
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({ { i, j }, 0 });
                    vis[i][j] = 2;
                }
            }
        }

        // bfs traversal
        int time = 0;
        vector<pair<int, int>> dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i].first;
                int nc = c + dir[i].second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && vis[nr][nc] == 0) {
                    vis[nr][nc] = 2;
                    q.push({ { nr, nc }, t + 1 });
                    time = max(time, t + 1);
                }
            }
        }

        // check if any orange is left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 2)
                    return -1;
            }
        }

        return time;
    }
};
```
