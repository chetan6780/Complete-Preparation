# [62. Unique Paths](https://leetcode.com/problems/unique-paths/description/) 🌟🌟

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

### Recursive Solution

-   To reach at the end we can either go down or right, so we do it by recursion.
-   when we reach the goal we return 1.
-   if we go out of boundary we return 0

```cpp
class Solution {
private:
    int uniquePathsHelper(int m, int n, int i, int j)
    {
        if (i == m - 1 && j == n - 1)
            return 1;
        if (i >= m || j >= n)
            return 0;
        int right = uniquePathsHelper(m, n, i, j + 1);
        int down = uniquePathsHelper(m, n, i + 1, j);
        return right + down;
    }

public:
    int uniquePaths(int m, int n)
    {
        return uniquePathsHelper(m, n, 0, 0);
    }
};
```

### Memoization(Top Down Dp)

```cpp
class Solution {
private:
    int dp[101][101];
    int uniquePathsHelper(int m, int n, int i, int j)
    {
        if (i == m - 1 && j == n - 1)
            return 1;
        if (i >= m || j >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = uniquePathsHelper(m, n, i, j + 1);
        int down = uniquePathsHelper(m, n, i + 1, j);
        return dp[i][j] = right + down;
    }

public:
    int uniquePaths(int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        return uniquePathsHelper(m, n, 0, 0);
    }
};
```

<details>
<summary><b>Other type solution</b></summary>

### Recursive Solution (TLE)

-   **Time Complexity: O(2^n)**

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<1||n<1) return 0;
        if(m==1||n==1) return 1;

        return uniquePaths(m-1,n)+uniquePaths(m,n-1);
    }
};
```

### Recursive + Memoization

-   remember to store calculated values in a dp - last line.
-   **Time complexity: m x n**
-   **Space complexity: m x n**

```cpp
class Solution{
private:
    int dfs(int m, int n, vector<vector<int>> &dp){
        if (m < 0 || n < 0) return 0;
        if (m == 0 || n == 0) return 1;
        if(dp[m][n]>0) return dp[m][n];
        return dp[m][n] = dfs(m - 1, n, dp) + dfs(m, n - 1, dp);
    }

public:
    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(m - 1, n - 1, dp);
    }
};
```

---

 </details>
### Tabulation Solution

-   **Time complexity: m x n**
-   **Space complexity: m x n**

```cpp
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        int dp[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
```

### Combinatorics Solution

-   **Time complexity: O(min(m,n))**
-   Explained in [striver's video](https://www.youtube.com/watch?v=t_f0nwwdg5o&t=23s).

```cpp
class Solution{
public:
    int uniquePaths(int m, int n){
        int N = n + m - 2;
        int r = m - 1;
        double res = 1;

        for (int i = 1; i <= r; i++){
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};
```

### READ

-   [ [C++/Python] 5 Simp le Solutions w/ Explanation | Optimization from Brute-Force to DP to Math](https://leetcode.com/problems/unique-paths/discuss/1581998/C%2B%2BPython-4-Simple-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP-to-Math)
-   [Recursive, memoization and dynamic programming solutions](https://leetcode.com/problems/unique-paths/discuss/182143/Recursive-memoization-and-dynamic-programming-solutions)
