# [Best Time to Buy and Sell Stock III](https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos) 🌟🌟🌟

**ONLY TWO TRANSACTIONS ARE ALLOWED**

### Recursion

-   The approach is same as previous problem, Here we need to have one other variable `cap` which represents what are the remaining transactions.
-   Initial value of `cap` is `2`, meaning we can do `2` transaction. `0` means transactions exceeded.
-   If we can buy stock,
    -   `buyStock` = pay `price[i]` and move to the next day where we cannot buy again. Transaction is not completed until we sell this stock so `cap` remain as it is.
    -   `dontBuyStock` = don't pay any price and move to next day where we can buy.
-   If we cannot buy stock,we can sell it or not sell it,
    -   `sellStock` = get the `price[i]` and move forward where we can start to buy again. Here transaction completes as we have sold the stock, so `cap-1`.
    -   `dontSellStock` = we don't get anything. move to next day where we cannot buy till we sell current stock. Transaction is not completed to no effects on `cap`.
-   In both cases return the maximum of 2 actions which can do.

### Code

```cpp
int f(vector<int>& prices, int n, int ind, int buy, int cap)
{
    if (ind == n || cap == 0)
        return 0;

    if (buy == 1) {
        int buyStock = -prices[ind] + f(prices, n, ind + 1, 0, cap);
        int dontBuyStock = f(prices, n, ind + 1, 1, cap);
        return max(buyStock, dontBuyStock);
    } else {
        int sellStock = prices[ind] + f(prices, n, ind + 1, 1, cap - 1);
        int dontSellStock = f(prices, n, ind + 1, 0, cap);
        return max(sellStock, dontSellStock);
    }
}

int maxProfit(vector<int>& prices, int n)
{
    return f(prices, n, 0, 1, 2);
}
```

### Memoization(top-down)

-   Here 3 variables are changing so we will use 3d dp.
-   **TC: O(n\*2\*3)**
-   **SC: O(n\*2\*3)**

### Code

```cpp
int f(vector<int>& prices, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp)
{
    if (ind == n || cap == 0)
        return 0;

    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    if (buy == 1) {
        int buyStock = -prices[ind] + f(prices, n, ind + 1, 0, cap, dp);
        int dontBuyStock = f(prices, n, ind + 1, 1, cap, dp);
        return dp[ind][buy][cap] = max(buyStock, dontBuyStock);
    } else {
        int sellStock = prices[ind] + f(prices, n, ind + 1, 1, cap - 1, dp);
        int dontSellStock = f(prices, n, ind + 1, 0, cap, dp);
        return dp[ind][buy][cap] = max(sellStock, dontSellStock);
    }
}

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    return f(prices, n, 0, 1, 2, dp);
}
```

### Tabulation(bottom-up)

-   Here in tabulation we don't need to write base condition as we are already filling table with 0. We can proceed with main logic and recursive relation.
-   **TC: O(n\*2\*3)**
-   **SC: O(n\*2\*3)**

### Code

```cpp
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy == 1) {
                    int buyStock = -prices[ind] + dp[ind + 1][0][cap];
                    int dontBuyStock = dp[ind + 1][1][cap];
                    dp[ind][buy][cap] = max(buyStock, dontBuyStock);
                } else {
                    int sellStock = prices[ind] + dp[ind + 1][1][cap - 1];
                    int dontSellStock = dp[ind + 1][0][cap];
                    dp[ind][buy][cap] = max(sellStock, dontSellStock);
                }
            }
        }
    }
    return dp[0][1][2];
}
```

### Space Optimized Tabulation(bottom-up)

-   ```
      dp[i+1] = after
      dp[i] = curr
    ```
-   Don't forget to assign `after to curr` at the end of each iteration.
-   **TC: O(n\*2\*3)**
-   **SC: O(2\*3) = constant**

```cpp
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<int>> curr(2, vector<int>(3, 0)), after(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy == 1) {
                    int buyStock = -prices[ind] +after[0][cap];
                    int dontBuyStock =after[1][cap];
                    curr[buy][cap] = max(buyStock, dontBuyStock);
                } else {
                    int sellStock = prices[ind] +after[1][cap - 1];
                    int dontSellStock =after[0][cap];
                    curr[buy][cap] = max(sellStock, dontSellStock);
                }
            }
        }
        after = curr; // Don't forget this line
    }
    return after[1][2];
}
```

### Other Solution

-   Other approach discussed by striver is already written by me [here](../../Leetcode/123_bestTimeToBuySellStockIII.md).
