# Minimum subset sum difference

Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

### Prerequisite: [Equal Sum Partition Problem](./AV3_equalSumPartition.md)

```
We want to find minimum diff between S1 and S2 -> i.e. s1-s2 = min()
if sum is total sum of array
then, s1 = sum - s2;
then, we can say,
s1 - s2 =  min()
(sum - s2) - s2 =  min()
sum - 2*s2 = min()
```

So , we should find **min(sum - 2 \* S)** for only **half array**, where S is subset of array.

### Code

```cpp

int minDifference(int arr[], int n)
{
    // Equal sum partion/subset sum code below
    int sum = accumulate(arr, arr + n, 0);
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

    // New code - store exact half of last row in vector if element is true
    int half;
    if (sum % 2 == 0)
        half = (sum / 2) + 1;
    else
        half = (sum + 1) / 2;

    // if we take first half we dont need to take absolute value else we take second half we have to take absolute value while taking difference i.e.(abs(sum - 2 * S))
    vector<int> v;
    for (int i = 0; i < half; i++)
        if (dp[n][i])
            v.push_back(i);

    // Calculate minimum of (Prev_min, sum - 2*s) for every element in vector
    int mn = INT_MAX;
    for (auto x : v)
        mn = min(mn, sum - (2 * x));

    return mn;
}
```

### Complexity Analysis

- Time Complexity: **O(N\*|sum of array elements|)**
- Auxiliary Space: **O(N\*|sum of array elements|)**
- 1D dp solution available on gfg

### References

- GFG: [Minimum subset sum difference](https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/)
- Youtube: [AV - Minimum subset sum difference](https://www.youtube.com/watch?v=-GtpxG6l_Mc)
