# [1289. Minimum Falling Path Sum II](https://leetcode.com/problems/minimum-falling-path-sum-ii/) 🌟🌟🌟

Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

### Recursion (TLE)

-   From every element in the first row of grid we find min answer.
-   we have to try all the columns except the current column in the recursion and get the minimum answer.
-   When we reach the last row, return the element itself.
-   also check for out of bounds.

### Code

```cpp
class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c, int i, int j)
    {
        if (i < 0 || i >= r || j < 0 || j >= c)
            return INT_MAX;
        if (i == r - 1)
            return grid[i][j];
        int res = INT_MAX;
        for (int colInd = 0; colInd < c; colInd++) {
            // try all columns of next row except current column
            if (colInd != j) {
                res = min(res, dfs(grid, r, c, i + 1, colInd));
            }
        }
        return grid[i][j] + res;
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        int ans = INT_MAX;
        for (int j = 0; j < c; j++) {
            ans = min(ans, dfs(grid, r, c, 0, j));
        }
        return ans;
    }
};
```

### Memoization

-   We use memoization table to store the result of subproblems.
-   We can return directly from the table if the computation is already done, else we store new computation.

### Code

```cpp

class Solution {
private:
    int dp[201][201];
    int dfs(vector<vector<int>>& grid, int r, int c, int i, int j)
    {
        if (i < 0 || i >= r || j < 0 || j >= c)
            return INT_MAX;
        if (i == r - 1)
            return grid[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];

        int res = INT_MAX;
        for (int colInd = 0; colInd < c; colInd++) {
            if (colInd != j) {
                res = min(res, dfs(grid, r, c, i + 1, colInd));
            }
        }
        return dp[i][j] = grid[i][j] + res;
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int ans = INT_MAX;
        for (int j = 0; j < c; j++) {
            ans = min(ans, dfs(grid, r, c, 0, j));
        }
        return ans;
    }
};
```

### Tabulation (AC)

-   The memoization solution can be converted into tabulation.

### Code

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(r, vector<int>(c, 0));
        // fill first row
        for (int j = 0; j < c; j++) {
            dp[0][j] = grid[0][j];
        }
        // fill rest of the rows
        for (int i = 1; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int res = INT_MAX;
                for (int colInd = 0; colInd < c; colInd++) {
                    if (colInd != j) {
                        res = min(res, dp[i - 1][colInd]);
                    }
                }
                dp[i][j] = grid[i][j] + res;
            }
        }
        // find min of last row
        for (int j = 0; j < c; j++) {
            ans = min(ans, dp[r - 1][j]);
        }
        return ans;
    }
};
```
