# [329. Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)

### DFS with memoization

-   Self-explanatory

```cpp
class Solution {
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int prev, int r, int c)
    {
        if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size() || matrix[r][c] <= prev) {
            return 0;
        }
        if (dp[r][c] != 0) {
            return dp[r][c];
        }

        int up = dfs(matrix, dp, matrix[r][c], r - 1, c) + 1;
        int down = dfs(matrix, dp, matrix[r][c], r + 1, c) + 1;
        int left = dfs(matrix, dp, matrix[r][c], r, c - 1) + 1;
        int right = dfs(matrix, dp, matrix[r][c], r, c + 1) + 1;
        dp[r][c] = max({ left, right, up, down });

        return dp[r][c];
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0) {
                    ans = max(ans, dfs(matrix, dp, INT_MIN, i, j));
                }
            }
        }
        return ans;
    }
};
```
