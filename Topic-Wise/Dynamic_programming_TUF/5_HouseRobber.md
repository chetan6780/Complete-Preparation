# [Maximum sum of non-adjacent elements](https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0) 🌟🌟

This problem is same as leetcode [House Robber](https://leetcode.com/problems/house-robber/).

### Recursive Approach

-   For index `i`, `f(i)` is the maximum sum of non-adjacent elements till index `i`.
    `f(i) = ...+ nums[i-4] + nums[i-2] + nums[i]`
-   Represent problem in form of index.
-   For each index,
    -   If i pick i'th element then sum = `nums[i] + f(i-2)`
    -   If i don't pick i'th element then sum = `0 + f(i-1)`
-   If we reach index `0` then it means we haven't picked 1st indexed element. so we can safely return `nums[0]`.
-   For case `i-2`, it can become negative. So we need to handle that case and return `0` in that case.

### Code

```cpp
int helper(vector<int>& nums, int i)
{
    if (i == 0) return nums[0]; // Base 1
    if (i < 0) return 0; // Base 2

    int pick = nums[i] + helper(nums, i - 2);
    int nonPick = helper(nums, i - 1);

    return max(pick, nonPick);
}

int maximumNonAdjacentSum(vector<int>& nums)
{
    int n = nums.size();
    return helper(nums, n - 1);
}
```

### Memoization(Top-Down) Approach

-   Use extra array to store the result of subproblems.
-   **TC: O(n)**
-   **SC: O(n)**

### Code

```cpp
int helper(vector<int>& nums, vector<int>& memo, int i)
{
    if (i == 0) return nums[0]; // Base 1
    if (i < 0) return 0; // Base 2

    if (memo[i] != -1) return memo[i];

    int pick = nums[i] + helper(nums, memo, i - 2);
    int nonPick = helper(nums, memo, i - 1);

    return memo[i] = max(pick, nonPick);
}
int maximumNonAdjacentSum(vector<int>& nums)
{
    int n = nums.size();
    vector<int> memo(n + 1, -1);
    return helper(nums, memo, n - 1);
}
```

### Tabulation(Bottom-Up) Approach

-   Convert base cases into dp array format.
-   write loop to simulate recursive calls.
-   return last element of dp array.

### Code

```cpp
int maximumNonAdjacentSum(vector<int>& nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0]; // 1st base case
    for (int i = 1; i < n; i++) {

        int pick = nums[i];
        if (i > 1) pick += dp[i - 2]; // 2nd base case

        int nonPick = dp[i - 1];

        dp[i] = max(pick, nonPick);
    }
    return dp[n - 1];
}
```

### Space Optimized Tabulation(Bottom-Up) Approach

-   As striver said, if problem involved `i-1` and `i-2` then it can be solved in `O(1)` space.
-   Represent each dp element as variable so we need 2 variables.
    ```
    prev2 = dp[n-2];
    prev1 = dp[n-1];
    ```
-   Recurrence relation is, `curr = max(pick, notPick);`
- Return `dp[n-1]` i.e. `prev1`.

### Code

```cpp
int maximumNonAdjacentSum(vector<int>& nums)
{
    int n = nums.size();
    int prev1 = nums[0]; // 1st base case
    int prev2 = 0;

    for (int i = 1; i < n; i++) {

        int pick = nums[i];
        if (i > 1) pick += prev2; // 2nd base case

        int nonPick = prev1;

        int curr = max(pick, nonPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
```
