# Replace O's with X's

-   [GFG](https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1)
-   [Leetcode](https://leetcode.com/problems/surrounded-regions/)

### DFS

-   **TC: O(N\*M)**
-   **SC: O(N\*M)**

```cpp
class Solution {
private:
    vector<pair<int, int>> dirs = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    void dfs(int r, int c, vector<vector<char>>& mat, vector<vector<int>>& vis)
    {
        int n = mat.size();
        int m = mat[0].size();
        vis[r][c] = 1;
        for (auto dir : dirs) {
            int nr = r + dir.first;
            int nc = c + dir.second;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 'O' && !vis[nr][nc]) {
                dfs(nr, nc, mat, vis);
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // first row and last row
        for(int j = 0; j < m; j++) {
            if(mat[0][j] == 'O' && !vis[0][j]) {
                dfs(0, j, mat, vis);
            }
            if(mat[n - 1][j] == 'O' && !vis[n - 1][j]) {
                dfs(n - 1, j, mat, vis);
            }
        }

        // first col and last col
        for(int i = 0; i < n; i++) {
            if(mat[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, mat, vis);
            }
            if(mat[i][m - 1] == 'O' && !vis[i][m - 1]) {
                dfs(i, m - 1, mat, vis);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 'O' && !vis[i][j]) {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};
```
