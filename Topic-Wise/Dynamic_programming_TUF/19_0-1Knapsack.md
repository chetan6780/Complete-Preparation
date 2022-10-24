# [0-1 Knapsack](https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?leftPanelTab=1) 🌟

### Recursive Solution

-   We have two options for each item, either we can take it or not take it.
-   We can only take item if its weight is less than or equal to the capacity of the knapsack.
-   For the base case we can take item if its weight is equal to the capacity of the knapsack else return 0.

### Code

```cpp
int f(vector<int>& wt, vector<int>& val, int mw, int i)
{
    if (i == 0) {
        if (wt[0] <= mw) return val[0];
        return 0;
    }

    int notTake = f(wt, val, mw, i - 1, dp);
    int take = INT_MIN;
    if (wt[i] <= mw)
        take = val[i] + f(wt, val, mw - wt[i], i - 1, dp);

    return max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return f(weight, value, maxWeight, n - 1);
}
```

### Memoization(top-down)

-   We can use memoization to store the result of the subproblems and avoid recomputation.
-   **Time Complexity:** O(n \* W) where n is the number of items and W is the capacity of the knapsack.
-   **Space Complexity:** O(n \* W) where n is the number of items and W is the capacity of the knapsack.

### Code

```cpp
int f(vector<int>& wt, vector<int>& val, int mw, int i, vector<vector<int>>& dp)
{
    if (i == 0) {
        if (wt[0] <= mw) return val[0];
        return 0;
    }

    if (dp[i][mw] != -1) return dp[i][mw];

    int notTake = f(wt, val, mw, i - 1, dp);
    int take = INT_MIN;
    if (wt[i] <= mw)
        take = val[i] + f(wt, val, mw - wt[i], i - 1, dp);

    return dp[i][mw] = max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return f(weight, value, maxWeight, n - 1, dp);
}
```

### Tabulation(bottom-up)

-   For first row every W whose value is greater than or equal to the weight of the first item is filled with the value of the first item.
-   Other cells are filled with recursive formula.
-   **Time Complexity:** O(n \* W) where n is the number of items and W is the capacity of the knapsack.
-   **Space Complexity:** O(n \* W) where n is the number of items and W is the capacity of the knapsack.

### Code

```cpp
int knapsack(vector<int> wt, vector<int> val, int n, int mw)
{
    vector<vector<int>> dp(n, vector<int>(mw + 1, 0));
    for (int W = wt[0]; W <= mw; W++)
        dp[0][W] = val[0];

    for (int i = 1; i < n; i++) {
        for (int W = 0; W <= mw; W++) {
            int notTake = dp[i - 1][W];
            int take = INT_MIN;
            if (wt[i] <= W)
                take = val[i] + dp[i - 1][W - wt[i]];
            dp[i][W] = max(take, notTake);
        }
    }
    return dp[n - 1][mw];
}
```

### Space optimized Tabulation(bottom-up)

-   We can observe we need only previous row to fill the current row.
-   `prev = dp[i - 1]`
-   `curr = dp[i]`
-   **Time Complexity:** O(n \* W) where n is the number of items and W is the capacity of the knapsack.
-   **Space Complexity:** O(W) where W is the capacity of the knapsack.

### Code

```cpp
int knapsack(vector<int> wt, vector<int> val, int n, int mw)
{
    vector<int> prev(mw + 1, 0), curr(mw + 1, 0);

    for (int W = wt[0]; W <= mw; W++)
        prev[W] = val[0];

    for (int i = 1; i < n; i++) {
        for (int W = 0; W <= mw; W++) {
            int notTake = prev[W];
            int take = INT_MIN;
            if (wt[i] <= W)
                take = val[i] + prev[W - wt[i]];
            curr[W] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[mw];
}
```

### Space optimized Tabulation(bottom-up) only one array

-   We can observe that can fill prev array from right to left and it will not affect the result, because we are using only previous row to fill the current row.
-   Now If we can use previous array's right elements to fill it's left elements, we can use only one array.
-   **Time Complexity:** O(n \* W) where n is the number of items and W is the capacity of the knapsack.
-   **Space Complexity:** O(W) where W is the capacity of the knapsack. One array is used.

### Code

```cpp
int knapsack(vector<int> wt, vector<int> val, int n, int mw)
{
    vector<int> prev(mw + 1, 0);
    for (int i = wt[0]; i <= mw; i++)
        prev[i] = val[0];

    for (int i = 1; i < n; i++) {
        for (int W = mw; W >= 0; W--) { // Notice - loop reversed [mw->0]
            int notTake = prev[W];
            int take = INT_MIN;
            if (wt[i] <= W)
                take = val[i] + prev[W - wt[i]];
            prev[W] = max(take, notTake);
        }
    }
    return prev[mw];
}
```
