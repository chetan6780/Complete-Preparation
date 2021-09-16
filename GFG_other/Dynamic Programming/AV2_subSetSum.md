# Subset Sum Problem

Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

### Prerequisite: [0-1 Knapsack Problem](./AV1_01knapsack.md)

### Method 1: Naive recursive solution

- Base cases

  - if sum is 0 there its always possible to find solution
  - if n is 0 there is no way to find solution

- if last element is less than or equal to sum, we can get the answer or not get the answer
- else if sum is greater than last element there is no way to find solution.so we ignore that element and recurse with 1 less element.

### Code

```cpp

bool isSubsetSum(int n, int arr[], int sum)
{
    // if sum is 0 there its always possible to find solution
    if (sum == 0)
        return true;
    // if n is 0 there is no way to find solution
    if (n == 0)
        return false;

    // if last element is less than or equal to sum, we can get the answer or not get the answer
    if (arr[n - 1] <= sum)
        return isSubsetSum(n - 1, arr, sum) || (isSubsetSum(n - 1, arr, sum - arr[n - 1]));
    // else if sum is greater than last element there is no way to find solution
    else
        return isSubsetSum(n - 1, arr, sum);
}
```

### Complexity Analysis

The above solution may try all subsets of given set in worst case. Therefore time complexity of the above solution is exponential. _The problem is in-fact **NP-Complete** (There is no known polynomial time solution for this problem)_.

---

# DP APPROACHES

### A) Memoization (top-down)

```cpp
// Accoring to the constrins initialize the table;
int N = 102;
int M = 100005;
int dp[N][M];

void initialize()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            dp[i][j] = -1;
}

int isSubsetSumRec(int n, int arr[], int sum)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    // If this state is present, then return it
    if (dp[n - 1][sum] != -1)
        return dp[n - 1][sum];

    // else calculate and store new states.
    if (arr[n - 1] <= sum)
        return dp[n - 1][sum] = (isSubsetSumRec(n - 1, arr, sum) || (isSubsetSumRec(n - 1, arr, sum - arr[n - 1])));
    else
        return dp[n - 1][sum] = isSubsetSumRec(n - 1, arr, sum);
}
```

### Complexity Analysis

- Time Complexity: **O(sum\*n)**, where sum is the ‘target sum’ and ‘n’ is the size of array.
- Auxiliary Space: **O(sum\*n)**, as the size of 2-D array is sum\*n.

---

### B) Tabulation (bottoms-up)

```cpp
bool isSubsetSum(int n, int arr[], int sum)
{
    bool dp[n + 1][sum + 1];

    // first column with 0 sum requred is always possible
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = true;

    // first row(except for col-0) with given sum is not possible (n=0)
    for (int j = 1; j < sum + 1; j++)
        dp[0][j] = false;

    // fill the rest of the table in bottom up manner
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];

    return dp[n][sum];
}
```

### Complexity Analysis

- Time complexity: pseudo-polynomial
- Space complexity: O(sum\*n) , 2D dp array

---

### References

- GFG: [Subset Sum Problem](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)
- Youtube: [AV - Subset Sum](https://www.youtube.com/watch?v=_gPcYovP7wc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=7)
