# [Minimum Path Sum](https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?leftPanelTab=0) 🌟🌟

### Recursive Approach

-   Same as previous problem, but here we just need to add current element to the minimum of the two paths.
-   **TC: O(2^(m+n))**
-   **SC: O(m+n)**

### Code

```cpp
int f(vector<vector<int>>& grid, int r, int c)
{
    if (r < 0 || c < 0) return 1e9;
    if (r == 0 && c == 0) return grid[r][c];

    int up = f(grid, r - 1, c);
    int left = f(grid, r, c - 1);

    return grid[r][c] + min(up, left);
}
int minSumPath(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    return f(grid, n - 1, m - 1);
}
```

### Memoization(top-down)

-   Memoize the recursive function.
-   **TC: O(m\*n)**
-   **SC: O(m\*n)**, with recursive stack space.

### Code

```cpp
int f(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& dp)
{
    if (r < 0 || c < 0) return 1e9;
    if (r == 0 && c == 0) return grid[r][c];

    if (dp[r][c] != -1) return dp[r][c];

    int up = f(grid, r - 1, c, dp);
    int left = f(grid, r, c - 1, dp);

    return dp[r][c] = grid[r][c] + min(up, left);
}
int minSumPath(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(grid, n - 1, m - 1, dp);
}
```

### Tabulation(bottom-up)

-   Removes recursive stack space.
-   **TC: O(m\*n)**
-   **SC: O(m\*n)**, without recursive stack space.

### Code

```cpp
int minSumPath(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else {
                int up = i > 0 ? dp[i - 1][j] : INT_MAX;
                int left = j > 0 ? dp[i][j - 1] : INT_MAX;
                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
}
```

### Space optimized Tabulation(bottom-up)

-   dp[i-1] = prev
-   dp[i] = curr
-   **TC: O(m\*n)**
-   **SC: O(m)**

### Code

```cpp
int minSumPath(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++) {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                curr[j] = grid[i][j];
            else {
                int up = i > 0 ? prev[j] : INT_MAX;
                int left = j > 0 ? curr[j - 1] : INT_MAX;
                curr[j] = grid[i][j] + min(up, left);
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}
```
