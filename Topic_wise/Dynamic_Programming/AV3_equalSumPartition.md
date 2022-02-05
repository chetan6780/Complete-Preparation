# Equal Sum Partition Problem

Determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is the same.

### Prerequisite: [Subset Sum Problem](./AV2_subSetSum.md)

-   if sum of array is odd we cannot find equal partition. return false.
-   else sum is even then
    -   if there exists one partition with the halve sum, partition is always possible.
    -   else not.

### Code

```cpp
bool isSubsetSum(int n, int arr[], int sum)
{
    bool dp[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = true;

    for (int j = 1; j < sum + 1; j++)
        dp[0][j] = false;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];

    return dp[n][sum];
}

bool equalPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];

    // if sum of array is odd we cannot find equal partition
    if (sum % 2 != 0)
        return false;
    // else its even then we can find one partition with halve sum
    else
        return isSubsetSum(N, arr, sum/2);
}
```

### Complexity Analysis

-   Time Complexity: O(sum\*n)
-   Auxiliary Space: O(sum\*n)

-   **Optimized space complexity solution (O(sum)) available on gfg but that solution will not be feasible for arrays with big sum.**

### References

-   GFG: [Equal Sum Partition Problem](https://www.geeksforgeeks.org/partition-problem-dp-18/)
-   Youtube: [AV - Equal Sum Partition Problem](https://www.youtube.com/watch?v=UmMh7xp07kY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=8)
