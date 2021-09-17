# Unbounded Knapsack (Repetition of items allowed)

Given a knapsack weight W and a set of n items with certain value vali and weight wti, we need to calculate the maximum amount that could make up this quantity exactly. This is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item.

### Prerequisite: [0-1 Knapsack Problem](./AV1_01knapsack.md)

- only we need to change dp[i-1]\[j-wt[i-1]] to dp[i]\[j-wt[i-1]], because we can use item any number of times.

### Code

```cpp

int knapSack(int n, int W, int val[], int wt[])
{
    int dp[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}
```

### Complexity Analysis:

- Time Complexity: **O(N\*W)** - where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
- Auxiliary Space: **O(N\*W)** - The use of 2-D array of size ‘N\*W’.

---

### Space optimized 1D DP solution

```cpp

int knapSack(int n, int W, int val[], int wt[])
{
    int dp[W + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i <= W; i++)
        for (int j = 0; j < n; j++)
            if (wt[j] <= i)
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);

    return dp[W];
}
```

### Reference

- GFG: [Unbounded Knapsack](https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/)
- Youtube: [AV - Unbounded Knapsack](https://www.youtube.com/watch?v=aycn9KO8_Ls&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=13)
