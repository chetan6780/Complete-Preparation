# Coin change - II - Minimum number of coins

Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change? If it’s not possible to make change, print -1.

### Code

```cpp
int minCoins(int coins[], int M, int V)
{
    int dp[M + 1][V + 1];
    // first column is 0
    for (int i = 0; i < M + 1; i++)
        dp[i][0] = 0;
    // first row is INT_MAX - 1
    for (int j = 1; j < V + 1; j++)
        dp[0][j] = INT_MAX - 1;

    for (int i = 1; i < M + 1; i++)
        for (int j = 1; j < V + 1; j++)
        {
            if (coins[i - 1] <= j)
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    return dp[M][V] == INT_MAX - 1 ? -1 : dp[M][V];
}
```

### Complexity Analysis

- Time Complexity: O(M\*N),N = number of coins , M = sum requred
- Auxiliary Space: O(M\*N),N = number of coins , M = sum requred
- Space optimized 1D dp solution available at gfg.

### References

- GFG: [Coin change - II](https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/)
- YouTube: [AV - Coin change - II](https://www.youtube.com/watch?v=I-l6PBeERuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=16)
  > As shown in aditya verma video no need to initialize 2nd row.
