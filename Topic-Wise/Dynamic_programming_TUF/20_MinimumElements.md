# [Minimum elements/Coin change](https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0) 🌟🌟

### Recursive Approach

-   For each coin we have option to take it or not take it.
-   We can take coin only if it is less than or equal to the amount.
-   Take minimum of both the cases.
-   For base case, if amount is multiple of coin then we can take amount/coin number of coins, else return INT_MAX or any max value.

### Code

```cpp
int f(vector<int>& nums, int x, int i)
{
    if (i == 0) {
        if (x % nums[0] == 0) return x / nums[0];
        return 1e9;
    }

    int notTake = f(nums, x, i - 1);
    int take = 1e9;
    if (nums[i] <= x)
        take = 1 + f(nums, x - nums[i], i);

    return min(take, notTake);
}

int minimumElements(vector<int>& nums, int x)
{
    int n = nums.size();
    int res = f(nums, x, n - 1);
    return res == 1e9 ? -1 : res;
}
```

### Memoization

-   Memoization for reducing the time complexity.
-   **TC: O(n\*x)**
-   **SC: O(n\*x)**

### Code

```cpp
int f(vector<int>& nums, int x, int i, vector<vector<int>>& dp)
{
    if (i == 0) {
        if (x % nums[0] == 0) return x / nums[0];
        return 1e9;
    }
    if (dp[i][x] != -1) return dp[i][x];

    int notTake = f(nums, x, i - 1, dp);
    int take = 1e9;
    if (nums[i] <= x)
        take = 1 + f(nums, x - nums[i], i, dp);

    return dp[i][x] = min(take, notTake);
}

int minimumElements(vector<int>& nums, int x)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    int res = f(nums, x, n - 1, dp);
    return res == 1e9 ? -1 : res;
}
```

### Tabulation

### Code

```cpp
int minimumElements(vector<int>& nums, int x)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    // Base case
    for (int T = 0; T <= x; T++) {
        if (T % nums[0] == 0)
            dp[0][T] = T / nums[0];
        else
            dp[0][T] = 1e9;
    }

    for (int i = 1; i < n; i++) {
        for (int T = 0; T <= x; T++) {
            int notTake = dp[i - 1][T];
            int take = 1e9;
            if (nums[i] <= T)
                take = 1 + dp[i][T - nums[i]];
            dp[i][T] = min(take, notTake);
        }
    }
    return dp[n - 1][x] == 1e9 ? -1 : dp[n - 1][x];
}
```

### Space Optimized Tabulation

### Code

```cpp
int minimumElements(vector<int>& nums, int x)
{
    int n = nums.size();
    vector<int> prev(x + 1, 0), curr(x + 1, 0);
    for (int T = 0; T <= x; T++) {
        if (T % nums[0] == 0)
            prev[T] = T / nums[0];
        else
            prev[T] = 1e9;
    }
    for (int i = 1; i < n; i++) {
        for (int T = 0; T <= x; T++) {
            int notTake = prev[T];
            int take = 1e9;
            if (nums[i] <= T)
                take = 1 + curr[T - nums[i]];
            curr[T] = min(take, notTake);
        }
        prev = curr;
    }
    return prev[x] == 1e9 ? -1 : prev[x];
}
```
