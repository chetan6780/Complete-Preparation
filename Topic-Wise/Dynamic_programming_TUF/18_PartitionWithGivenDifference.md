# [Partition with given difference](https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?leftPanelTab=0) 🌟

### Solution

-   Similar to [Count subset with target sum](./17_CountSubsetWithTargetSum.md) problem.
-   we have,
    -   `s1 - s2 = diff`
    -   `(totalSum - s2) - s2 = diff`
    -   `totalSum - 2*s2 = diff`
    -   `s2 = (totalSum - diff)/2`
-   Count subsets with target sum `s2` and return it.
-   Sum `totalSum - diff` cannot be negative or odd, so return 0.

### Code

```cpp
int mod = 1e9 + 7;
int findWays(vector<int>& arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    // Following base conditions are to handle 0.
    if (arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if (arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++) {
        for (int target = 0; target <= k; target++) {
            int take = 0;
            if (arr[i] <= target)
                take = dp[i - 1][target - arr[i]];
            int notTake = dp[i - 1][target];

            dp[i][target] = (take + notTake) % mod; // don't forget mod
        }
    }

    return dp[n - 1][k];
}

int countPartitions(int n, int d, vector<int>& arr)
{
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    // DON'T FORGET TO CHECK THESE CONDITIONS
    if (totalSum - d < 0 || ((totalSum - d) % 2 == 1)) return 0;

    return findWays(arr, (totalSum - d) / 2);
}
```
