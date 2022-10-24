# [Subset Sum equals to k](https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0) 🌟🌟

### Recursive Solution

-   For a index we have two choices either to take that element or not to take that element.
-   We can take element only if it is less than or equal to the required target.
-   The base case arises when target reach to 0 or we go to first index.
-   For first index we return true only if the element is equal to target, else return false.

### Code

```cpp
bool f(vector<int>& arr, int n, int k, int i)
{
    if (k == 0) return true;
    if (i == 0) return (arr[i] == k);

    bool take = false;
    if (arr[i] <= k) take = f(arr, n, k - arr[i], i - 1);
    bool notTake = f(arr, n, k, i - 1);

    return (take || notTake);
}

bool subsetSumToK(int n, int k, vector<int>& arr)
{
    return f(arr, n, k, n - 1);
}
```

### Memoization(top-down) Solution

-   Memoize the solution to reduce the time complexity.
-   **NOTE:**: for memoization we need to take 2D vector of int and not bool, because -1 represent unvisited state and 0 represent false and 1 represent true.
-   **TC: O(n\*k)**
-   **SC: O(n\*k)**

### Code

```cpp
bool f(vector<int>& arr, int n, int k, int i, vector<vector<int>>& dp)
{
    if (k == 0) return true;
    if (i == 0) return (arr[i] == k);

    if (dp[i][k] != -1) return dp[i][k];

    bool take = false;
    if (arr[i] <= k) take = f(arr, n, k - arr[i], i - 1, dp);
    bool notTake = f(arr, n, k, i - 1, dp);

    return dp[i][k] = (take || notTake);
}

bool subsetSumToK(int n, int k, vector<int>& arr)
{
    // takeing 2D vector of int and not bool.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(arr, n, k, n - 1, dp);
}
```

### Tabulation(bottom-up) Solution

-   From memoization we can observe that value of 0'th column is true.
-   From 2nd base case we can say value at arr[0]=k'th column is true, if its less than or equal to target k.
-   Other representation is same as memoization.
-   **TC: O(n\*k)**
-   **SC: O(n\*k)**

### Code

```cpp
bool subsetSumToK(int n, int k, vector<int>& arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    // don't forget to check arr[0] <= k
    if(arr[0]<=k) dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= k; target++) {
            bool take = false;
            if (arr[i] <= target) take = dp[i - 1][target - arr[i]];
            bool notTake = dp[i - 1][target];

            dp[i][target] = (take || notTake);
        }
    }

    return dp[n - 1][k];
}
```

### Space Optimized Tabulation(bottom-up) Solution

-   We can observe that we are using only previous row to calculate current row.
-   Also 0'th column is always true.
-   ```
    prev = dp[i-1]
    curr = dp[i]
    ```
-   **TC: O(n\*k)**
-   **SC: O(k)**

### Code

```cpp
bool subsetSumToK(int n, int k, vector<int>& arr)
{
    vector<bool> prev(k + 1, false), curr(k + 1, false);
    prev[0] = true;
    curr[0] = true;
    // don't forget to check arr[0] <= k
    if(arr[0]<=k) prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        prev[0] = true; // from base case
        for (int target = 1; target <= k; target++) {
            bool take = false;
            if (arr[i] <= target)
                take = prev[target - arr[i]];
            bool notTake = prev[target];
            curr[target] = (take || notTake);
        }
        prev = curr;
    }

    return prev[k];
}
```
