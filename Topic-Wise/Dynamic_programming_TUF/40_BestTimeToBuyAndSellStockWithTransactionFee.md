# [Best time to buy and sell stocks with transaction fee](https://www.codingninjas.com/codestudio/problems/rahul-and-his-chocolates_3118974?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0) 🌟🌟

**UNLIMITED TRANSACTIONS BUT WITH TRANSACTION FEE**

### Solution

-   All solution of [stock II](./36_BestTimeToBuyAndSellStockII.md) can be used here.
-   Just need to add `-fee` when we complete a transaction.

### Code

```cpp
int maximumProfit(int n, int fee, vector<int>& prices)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy < 2; buy++) {
            int profit = 0;
            if (buy) {
                int buyStock = -prices[ind] + dp[ind + 1][0];
                int dontBuyStock = dp[ind + 1][1];
                profit = max(buyStock, dontBuyStock);
            } else {
                int sellStock = prices[ind] - fee + dp[ind + 1][1]; // Just reduce fee for completing the transaction
                int dontSellStock = dp[ind + 1][0];
                profit = max(sellStock, dontSellStock);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

```
