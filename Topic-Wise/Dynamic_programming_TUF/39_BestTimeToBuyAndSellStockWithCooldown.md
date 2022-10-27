# [Best Time to Buy and Sell Stock with Cooldown](https://www.codingninjas.com/codestudio/problems/highway-billboards_3125969?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos) 🌟🌟

**UNLIMITED TRANSACTIONS WITH 1 DAY COOLDOWN**

### Tabulation from stock II

-   All solutions are same as [stock II](./36_BestTimeToBuyAndSellStockII.md), just add 1 day cooldown, means just buy on i+1'th day instead of i+1'th day.
-   Don't forget to increase size of dp array by 1. (n+2).
-   **TC: O(n\*2) = O(n)**
-   **SC: O(n\*2) = O(n)**

### Code

```cpp
int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0)); // n+2 instead of n+1
    dp[n][0] = dp[n][1] = 0;
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit = 0;
            if (buy) {
                int buyStock = -prices[ind] + dp[ind + 1][0];
                int dontBuyStock = dp[ind + 1][1];
                profit = max(buyStock, dontBuyStock);
            } else {
                int sellStock = dp[ind + 1][0];
                int dontSellStock = prices[ind] + dp[ind + 2][1]; // ind+2 instead of ind+1
                profit = max(sellStock, dontSellStock);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}
```

### Removing redundant part

-   buy loop will execute only 2 times so buy and not buy always occur only one time. We can ommit that loop and directly calculate profit.
-   also for base condition we don't explicitly need to write `dp[n][0] = dp[n][1] = 0;` as its already 0.
-   **TC: O(n)**
-   **SC: O(n)**

### Code

```cpp
int stockProfit(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0)); // n+2 instead of n+1

    for (int ind = n - 1; ind >= 0; ind--) {
        dp[ind][1] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
        dp[ind][0] = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]); // ind+2
    }
    return dp[0][1];
}

```

### Space optimized tabulation

-   ```
    dp[i+2] = front2
    dp[i+1] = front1
    dp[i] = curr
    ```
-   **TC: O(n)**
-   **SC: O(6)=O(1)**

### Code

```cpp
int stockProfit(vector<int>& prices)
{
    int n = prices.size();
    vector<int> front2(2, 0);
    vector<int> front1(2, 0);
    vector<int> curr(2, 0);

    for (int ind = n - 1; ind >= 0; ind--) {
        curr[1] = max(-prices[ind] + front1[0], front1[1]);
        curr[0] = max(prices[ind] + front2[1], front1[0]);
        front2 = front1;
        front1 = curr;
    }
    return curr[1];
}
```

### Other solutions

-   My other solutions to this problem can be found [here](../../Leetcode/309_bestTimeToBuyAndSellStockWithCooldown.md).
