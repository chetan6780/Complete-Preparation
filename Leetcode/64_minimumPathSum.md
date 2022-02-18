# [64. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) 🌟🌟

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

**Note:** You can only move either down or right at any point in time.

### Recursion (TLE)

-   For a cell in grid we can go either right or down.
-   We take minimum of right path and down path with current cell's value.
-   The base case arises when we reach to the last cell, then we return that cell's value.
-   also if we go out of bound the we return `INT_MAX`, because we are taking minimum of right and down.

### Code

```cpp
class Solution {
private:
    int dfs(vector<vector<int>>& grid, int m, int n, int i, int j)
    {
        if (i >= m || j >= n)
            return INT_MAX;
        if (i == m - 1 && j == n - 1)
            return grid[i][j];
        int right = dfs(grid, m, n, i + 1, j);
        int down = dfs(grid, m, n, i, j + 1);
        return grid[i][j] + min(right, down);
    }

public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return dfs(grid, m, n, 0, 0);
    }
};
```

### Memoization (AC)

-   The recursive solution will result in TLE, because of representing subproblems.
-   We can use memoization table to remember the result of subproblems.
-   If we have already computed the values of the subproblem then we directly return it from the table.
-   If we encounter new subproblem then we store it in the table.
-   **TC: O(m\*n)**
-   **SC: O(m\*n)**

### Code

```cpp
class Solution {
private:
    int dp[201][201];
    int dfs(vector<vector<int>>& grid, int m, int n, int i, int j)
    {
        if (i >= m || j >= n)
            return INT_MAX;
        if (i == m - 1 && j == n - 1)
            return grid[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = dfs(grid, m, n, i + 1, j);
        int down = dfs(grid, m, n, i, j + 1);
        return dp[i][j] = grid[i][j] + min(right, down);
    }

public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return dfs(grid, m, n, 0, 0);
    }
};
```

### Tabulation (AC)

-   We can convert memoization method to tabulation method.
-   first we fill the bottom-right corner with the value of `grid[m-1][n-1]`, because it **Don't have any other choice**.
-   Then we fill last row and last column, because they have **Only one choice**.
-   Rest we can fill with regular method, they have **Two choices** we take minimum of both.
-   **TC: O(m\*n)**
-   **SC: O(m\*n)**

### Code-1

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(r, vector<int>(c, INT_MAX));

        // fill bottom-right corner
        dp[r - 1][c - 1] = grid[r - 1][c - 1];

        // fill last row
        for (int i = r - 2; i >= 0; i--) {
            dp[i][c - 1] = grid[i][c - 1] + dp[i + 1][c - 1];
        }

        // fill last column
        for (int i = c - 2; i >= 0; i--) {
            dp[r - 1][i] = grid[r - 1][i] + dp[r - 1][i + 1];
        }

        // fill the rest
        for (int i = r - 2; i >= 0; i--) {
            for (int j = c - 2; j >= 0; j--) {
                dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        // return the top-left corner
        return dp[0][0];
    }
};
```

-   The above code can also written as:

### Code-2

```cpp

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));

        // fill top-left corner
        dp[0][0] = grid[0][0];

        // fill first row
        for (int i = 1; i < c; i++)
            dp[0][i] = grid[0][i] + dp[0][i - 1];

        // fill first column
        for (int i = 1; i < r; i++)
            dp[i][0] = grid[i][0] + dp[i - 1][0];

        // fill the rest
        for (int i = 1; i < r; i++)
            for (int j = 1; j < c; j++)
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);

        // return the last element
        return dp[r - 1][c - 1];
    }
};
```
