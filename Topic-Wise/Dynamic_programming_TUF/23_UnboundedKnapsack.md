# [Unbounded Knapsack](https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?leftPanelTab=0) 🌟🌟

### Solution

-   Same as [0-1 Knapsack](./19_0-1Knapsack.md) problem.
-   But for take case we don't go to `i-1`, we keep `i` as it is.
-   And for base case we return how many times we can take the item. `((wight/itemWeight) * cost)`.
-   All solution of 0-1 Knapsack can be applied here with above modifications.

### Code

```cpp
int unboundedKnapsack(int n, int mw, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(mw + 1, 0));
    for (int W = wt[0]; W <= mw; W++)
        dp[0][W] = (W/wt[0])*val[0]; // change here

    for (int i = 1; i < n; i++) {
        for (int W = 0; W <= mw; W++) {
            int notTake = dp[i - 1][W];
            int take = INT_MIN;
            if (wt[i] <= W)
                take = val[i] + dp[i][W - wt[i]]; // change here
            dp[i][W] = max(take, notTake);
        }
    }
    return dp[n - 1][mw];
}
```
