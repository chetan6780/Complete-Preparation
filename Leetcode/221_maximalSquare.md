# [221. Maximal Square](https://leetcode.com/problems/maximal-square/) 🌟🌟

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

### Dynamic Programming

-   1 square itself can create a square.
-   Also We can observe that if there are 1 in cell above, cell left and cell diagonally then we can create a new 2x2 square.
-   So the relation can be found as `dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1`
-   Also we maintain a max_sq to get the maximum ans.
-   finally we return max_sq \*\* 2
-   **TC: O(nm)**,n=row , m=col
-   **SC: O(nm)**

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix){
        int n = matrix.size(), m = matrix[0].size();
        if (n < 1) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int max_sq = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    max_sq = max(max_sq, dp[i][j]);
                }
            }
        }

        return max_sq * max_sq;
    }
};
```

### READ

-   [[Python] Thinking Process Diagrams - DP Approach](https://leetcode.com/problems/maximal-square/discuss/600149/Python-Thinking-Process-Diagrams-DP-Approach)
