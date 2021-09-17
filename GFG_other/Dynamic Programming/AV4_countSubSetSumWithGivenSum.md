# Count of subset sum with given sum

Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X.

### Prerequisite: [Subset Sum Problem](./AV2_subSetSum.md)

- We just need to fill with ints instead of bools.
- Instead of || we have to write +

### code

```cpp
int countSubsetSum(int n, int arr[], int sum)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;

    for (int j = 1; j < sum + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];

    return dp[n][sum];
}
```

### Complexity Analysis

- Time Complexity: O(sum\*n)
- Auxiliary Space: O(sum\*n)

### References

- GFG: [Count of subset sum with given sum](https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/)
- Youtube: [AV - Count of subset sum with given sum](https://www.youtube.com/watch?v=F7wqWbqYn9g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=9)
