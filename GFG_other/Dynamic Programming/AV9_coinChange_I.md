# Coin change - I - Maximum number of Ways

Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.

### Prerequisite:

- [Unbounded Knapsack Problem](./AV7_unboundedKnapsack.md)
- [Count of subset sum with given sum](./AV4_countSubSetSumWithGivenSum.md)

### Code

```cpp
long long int count(int s[], int n, int sum)
{
    long long int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;
    for (int j = 0; j < sum + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (s[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - s[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
```

### Complexity Analysis

- Time Complexity: **O(M\*N)**,N = number of coins , M = sum requred
- Auxiliary Space: **O(M\*N)**,N = number of coins , M = sum requred
- Space optimized 1D dp solution available at gfg.

### References

- GFG: [coin change](https://www.geeksforgeeks.org/coin-change-dp-7/)
- Youtube: [AV - Coin change I](https://www.youtube.com/watch?v=I4UR2T6Ro3w&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=15&t=2s)
