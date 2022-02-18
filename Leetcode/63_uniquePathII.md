# [63. Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) 🌟🌟

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

### Recursion (TLE)

-   The straightforward solution is to use recursion.
-   We have choice to go right or go down.
-   we return right + left as we want to find all the paths.
-   the base case arises when we reach to our destination i.e.(m-1, n-1), we return 1.
-   also if we encounter an obstacle Or one of our indexes goes out of range, we return 0.

```cpp
class Solution {
private:
    int helper(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j)
    {
        if (i == m - 1 && j == n - 1)
            return 1;
        if (i >= m || j >= n)
            return 0;
         if (obstacleGrid[i][j] == 1)
            return 0;
        int right = helper(obstacleGrid, m, n, i, j + 1);
        int down = helper(obstacleGrid, m, n, i + 1, j);
        return right + down;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1)
            return 0;
        return helper(obstacleGrid, m, n, 0, 0);
    }
};
```

### Memoization (AC)

-   The above recursion solution calculates same subproblem again and again results in TLE.
-   We can use memoization to store the result of subproblems in dp table.
-   If we already calculated the solution return it.
-   **TC: O(m\*n)**
-   **SC: O(m\*n)**

```cpp
class Solution {
private:
    int dp[101][101];
    int helper(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j)
    {
        if (i == m - 1 && j == n - 1)
            return 1;
        if (i >= m || j >= n)
            return 0;
        if (obstacleGrid[i][j] == 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = helper(obstacleGrid, m, n, i, j + 1);
        int down = helper(obstacleGrid, m, n, i + 1, j);
        return dp[i][j] = right + down;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        memset(dp, -1, sizeof(dp));
        return helper(obstacleGrid, m, n, 0, 0);
    }
};
```

### Tabulation (AC)

-   We can also use tabulation to solve this problem.
-   But here are some edge case that we have to take care.
-   we fill first row with 1 and first column with 1.
-   but at any point in 1st row or column we encounter an obstacle, we set the all farther value to 0.
-   other things are same as recursion.
-   **TC: O(m\*n)**
-   **SC: O(m\*n)**

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // fill first row with 1 until we reach to the obstacle or the end of the row
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = 1;
            } else {
                break;
            }
        }

        // fill first column with 1 until we reach to the obstacle or the end of the column
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = 1;
            } else {
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
```
