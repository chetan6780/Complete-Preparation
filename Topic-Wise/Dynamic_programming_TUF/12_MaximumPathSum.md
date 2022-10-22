# [Maximum Path Sum in Matrix](https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?leftPanelTab=0) 🌟🌟

### Recursive Approach

-   In this problem we have variable positions to start with, so to take optimal we try all possible positions and take the maximum of them.
-   Now to the recursive function.
-   We can reach to the last row from left diagonal, right diagonal, or from the same column of the previous row.
-   We need to take maximum of these 3 paths and add current element in it.
-   But before we do any operation we need check for valid indexes, if its not valid return INT_MIN.
-   For the base case, if we reach at the first row we can have that element with us so we return it.
-   **TC: O(3^N)**
-   **SC: O(N)**

```cpp
int f(vector<vector<int>>& matrix, int n, int m, int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return INT_MIN;
    if (i == 0)
        return matrix[i][j];

    int lDig = f(matrix, n, m, i - 1, j - 1);
    int rDig = f(matrix, n, m, i - 1, j + 1);
    int up = f(matrix, n, m, i - 1, j);

    return matrix[i][j] + max({ lDig, up, rDig });
}

int getMaxPathSum(vector<vector<int>>& matrix)
{
    int res = INT_MIN;
    int n = matrix.size(), m = matrix[0].size();

    // check for every column in the last row
    for (int j = 0; j < m; j++) {
        int currSum = f(matrix, n, m, n - 1, j);
        res = max(res, currSum);
    }
    return res;
}
```

### Memoization(top-down)

-   Memoize the solution to reduce space complexity.
-   **TC: O(N\*M)**
-   **SC: O(N\*M)**, with stack space.

```cpp
int f(vector<vector<int>>& matrix, int n, int m, int i, int j, vector<vector<int>>& dp)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return INT_MIN;
    if (i == 0)
        return matrix[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int lDig = f(matrix, n, m, i - 1, j - 1, dp);
    int rDig = f(matrix, n, m, i - 1, j + 1, dp);
    int up = f(matrix, n, m, i - 1, j, dp);

    return dp[i][j] = matrix[i][j] + max({ lDig, up, rDig });
}

int getMaxPathSum(vector<vector<int>>& matrix)
{
    int res = INT_MIN;
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int j = 0; j < m; j++) {
        int currSum = f(matrix, n, m, n - 1, j, dp);
        res = max(res, currSum);
    }
    return res;
}
```

### Tabulation(Bottom-up)

-   In memoization base case was to return element of first row, so we store first row in dp.
-   We were going from n-1 to 1, so we can go from 1 to n-1.
-   Try for every column to get maximum path.
-   Here for j we need to check for its validity, is it out of bound or not.
-   Finally get the maximum path sum from last row of dp vector.
-   **O(N\*M)**
-   **O(N\*M)**, without stack space.

```cpp
int getMaxPathSum(vector<vector<int>>& matrix)
{
    int res = INT_MIN;
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = dp[i - 1][j];
            int lDig = (j - 1 >= 0) ? dp[i - 1][j - 1] : INT_MIN; // check for valid j
            int rDig = (j + 1 < m) ? dp[i - 1][j + 1] : INT_MIN; // check for valid j

            dp[i][j] = matrix[i][j] + max({ lDig, up, rDig });
        }
    }

    // get maximum from last row
    for (int j = 0; j < m; j++) {
        res = max(res, dp[n - 1][j]);
    }
    return res;
}
```

### Space Optimized Tabulation

-   We can observe that we only need previous and current row for calculation so,
-   ```
      dp[i - 1] = prev
      dp[i] = curr
    ```
-   **TC: O(N\*M)**
-   **SC: O(M)**

```cpp
int getMaxPathSum(vector<vector<int>>& matrix)
{
    int res = INT_MIN;
    int n = matrix.size(), m = matrix[0].size();
    vector<int> prev(m, 0), curr(m, 0);

    for (int j = 0; j < m; j++) {
        prev[j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = prev[j];
            int lDig = (j - 1 >= 0) ? prev[j - 1] : INT_MIN; // check for valid j
            int rDig = (j + 1 < m) ? prev[j + 1] : INT_MIN; // check for valid j

            curr[j] = matrix[i][j] + max({ lDig, up, rDig });
        }
        prev = curr;
    }

    // get maximum from last row
    for (int j = 0; j < m; j++) {
        res = max(res, prev[j]);
    }
    return res;
}
```
