# [Unique Paths](https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?leftPanelTab=0) 🌟🌟

### Recursive Solution

-   For the problem we start from position (m-1, n-1) and we have to reach (0, 0).
-   While traveling if our index goes out of bound then we return 0.
-   If we reach (0, 0) then we return 1.
-   Else we call the function recursively for (m-1, n) and (m, n-1) and add the result.
-   **TC: O(2^(m+n))**
-   **SC: O(m+n)**, It also has recursive stack space.

### Code

```cpp
int f(int m, int n, int r, int c)
{
    if (r < 0 || c < 0) return 0;
    if (r == 0 && c == 0) return 1;
    return f(m, n, r - 1, c) + f(m, n, r, c - 1);
}
int uniquePaths(int m, int n)
{
    return f(m, n, m - 1, n - 1);
}
```

### Memoization(top-down)

-   The recursive solution has overlapping subproblems. So we can use memoization to solve this problem.
-   As there are only two states changing, r,c, we can use a 2D array to store the result.
-   **TC: O(m\*n)**
-   **SC: O(m\*n)**

### Code

```cpp
int f(int m, int n, int r, int c, vector<vector<int>> &dp)
{
    if (r < 0 || c < 0) return 0;
    if (r == 0 && c == 0) return 1;
    if (dp[r][c] != -1) return dp[r][c];
    return dp[r][c] = f(m, n, r - 1, c, dp) + f(m, n, r, c - 1, dp);
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m, n, m - 1, n - 1, dp);
}
```

### Tabulation(bottom-up)

-   To reduce recursive stack space, we can use tabulation.
-   **TC: O(m\*n)**
-   **SC: O(m\*n)**, Without recursive stack space.

### Code

```cpp
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}
```

### Space optimized Tabulation(bottom-up)

-   As we can observe, to calculate current state we are just requiring previous row, so we only need to store previous row.
    ```
    dp[i] = currRow
    dp[i-1] = prevRow
    ```
-   After each i we update our current row with previous row.
-   **TC: O(m\*n)**
-   **SC: O(n)**

### Code

```cpp
int uniquePaths(int m, int n)
{
    vector<int> prevRow(n, 0); // n size row
    for (int i = 0; i < m; i++) {
        vector<int> currRow(n, 0);
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0)
                currRow[j] = 1;
            else
                currRow[j] = prevRow[j] + currRow[j - 1];
        }
        prevRow = currRow;
    }
    return prevRow[n - 1];
}
```
