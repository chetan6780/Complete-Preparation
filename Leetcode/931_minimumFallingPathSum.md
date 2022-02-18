# [931. Minimum Falling Path Sum](https://leetcode.com/problems/minimum-falling-path-sum/) 🌟🌟

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

### Recursion (TLE)

-   For an element we can go down, right diagonal, or left diagonal, we will take minimum of those 3 and add with current element.
-   The base case here is: If we reach to last row, we will return the current element.
-   Also we have to check if the element is out of bound, if it is then return `INT_MAX`, because we are taking minimum element.

```cpp
class Solution {
private:
    int dfs(vector<vector<int>>& matrix, int r, int c, int i, int j)
    {
        if (i < 0 || i >= r || j < 0 || j >= c)
            return INT_MAX;
        if (i == r - 1)
            return matrix[i][j];

        int down = dfs(matrix, r, c, i + 1, j);
        int leftDig = dfs(matrix, r, c, i + 1, j - 1);
        int rightDig = dfs(matrix, r, c, i + 1, j + 1);

        return matrix[i][j] + min({ down, leftDig, rightDig });
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        int ans = INT_MAX;
        for (int i = 0; i < r; i++) {
            ans = min(ans, dfs(matrix, r, c, 0, i));
        }
        return ans;
    }
};
```

### Memoization (AC)

-   The recursive solution calculate same subproblem multiple times.
-   we can use memoization table to store the results of the subproblems.
-   If the subproblem is already calculated then return it else calculate and store it.
-   **TC: O(m\*n)**
-   **SC: O(m\*n)**

```cpp
class Solution {
private:
    int dp[101][101];
    int dfs(vector<vector<int>>& matrix, int r, int c, int i, int j)
    {
        if (i < 0 || i >= r || j < 0 || j >= c)
            return INT_MAX;
        if (i == r - 1)
            return matrix[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];

        int down = dfs(matrix, r, c, i + 1, j);
        int leftDig = dfs(matrix, r, c, i + 1, j - 1);
        int rightDig = dfs(matrix, r, c, i + 1, j + 1);

        return dp[i][j] = matrix[i][j] + min({ down, leftDig, rightDig });
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        int ans = INT_MAX;
        for (int i = 0; i < r; i++) {
            ans = min(ans, dfs(matrix, r, c, 0, i));
        }
        return ans;
    }
};
```

### Tabulation (AC)

-   we fill the first row with original values.
-   then we fill rest as:
    -   for first col we take `min(up,upRightDig) + currElem`
    -   for last col we take `min(up,upLeftDig) + currElem`
    -   for all other cols we take `min(up,upLeftDig,upRightDig) + currElem`
-   Then we find the min of the last row.
-   **TC: O(m\*n)**
-   **SC: O(m\*n)**

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(r, vector<int>(c, 0));
        // fill the first row
        for (int j = 0; j < c; j++)
            dp[0][j] = matrix[0][j];

        // fill the rest of the matrix
        for (int i = 1; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (j == 0) { // for first col we take min(up,upRightDig)+currElem
                    dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1]);
                } else if (j == r - 1) { // for last col we take min(up,upLeftDig)+currElem
                    dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
                } else { // for all other cols we take min(up,upLeftDig,upRightDig)+currElem
                    dp[i][j] = matrix[i][j] + min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1] });
                }
            }
        }

        // find the min of the last row
        for (int j = 0; j < c; j++)
            ans = min(ans, dp[r - 1][j]);

        return ans;
    }
};
```
