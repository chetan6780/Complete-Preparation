# [Matrix chain multiplication](https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos) 🌟🌟

### Tabulation(bottom-up)

-   In memoization `i` was going from `1 to n-1` and in tabulation `i` will go from `n-1 to 1`.
-   Similarly `j` will go from `i+1 to n-1`. Why not from `1` to `n-1`? Because `i` will be always to the left of `j`, so it cannot start from `1` always.
-   Other table can be filled with the same recursive formula as memoization.
-   **TC: O(n^3)**
-   **SC: O(n^2)**

```cpp
int matrixMultiplication(vector<int>& arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = N - 1; i >= 1; i--) {
        for (int j = i + 1; j < N; j++) {
            int mn = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int steps = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                mn = min(mn, steps);
            }
            dp[i][j] = mn;
        }
    }
    return dp[1][N - 1];
}
```
