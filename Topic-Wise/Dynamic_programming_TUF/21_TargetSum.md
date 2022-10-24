# [Target Sum](https://www.codingninjas.com/codestudio/problems/target-sum_4127362) 🌟🌟

### Solution

-   Suppose we are giving + to half of the elements and - to the other half.
-   one half will be s1 and other will be s2.
-   s1 - s2 = target(d)
-   This problem is exactly same as [partition with given difference](./18_PartitionWithGivenDifference.md) problem.
-   All the solutions of partition with given difference problem can be applied here.
-   One of them is shown below.

### Code

```cpp
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

            dp[i][target] = (take + notTake); // don't forget mod
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
int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n,target,arr);
}
```
