# [62. Unique Paths](https://leetcode.com/problems/unique-paths/description/) 🌟🌟

-   **GOOGLE QUESTION**

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

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

-   Giving TLE , that should not happen , but it is happening.
-   **Time complexity**: m x n
-   **Space complexity**: m x n

```cpp
class Solution{
private:
    int helper(int m, int n, vector<vector<int>> &dp){
        if (m < 0 || n < 0) return 0;
        if (m == 0 || n == 0) return 1;
        if(dp[m][n]>0) return dp[m][n];
        return helper(m - 1, n, dp) + helper(m, n - 1, dp);
    }

public:
    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, dp);
    }
};
```

### Tabulation Solution

-   **Time complexity: m x n**
-   **Space complexity: m x n**

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0) dp[i][j]=1;
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
```

### Combinatorics Solution

-   **Time complexity**: liner O(m)
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

-   [Recursive, memoization and dynamic programming solutions](https://leetcode.com/problems/unique-paths/discuss/182143/Recursive-memoization-and-dynamic-programming-solutions)
