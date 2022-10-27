# [Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/) 🌟🌟

### Tabulation Solution

-   For such problems recursive and memoization solutions are not that intuitive, so we write tabulation directly.
-   For first row and column we can form squares of size 1 if the element is 1 else not, so fill the first row and column with the element present.
-   For other elements, if it is 1 then we can form min(top,left, lDigonal) + 1 squares, else we cannot form any square.
-   **TC: O(N\*M)**, N = number of rows, M = number of columns
-   **SC: O(N\*M)**, N = number of rows, M = number of columns

### Code

```cpp
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) { // fill first row and column as it is
                    dp[i][j] = matrix[i][j];
                } else if (matrix[i][j] == 1) { // current element is 1, dp is min(top,left,lDigonal)+1
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                } else {
                    dp[i][j] = 0; // current element is 0, so dp will be 0
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
```
