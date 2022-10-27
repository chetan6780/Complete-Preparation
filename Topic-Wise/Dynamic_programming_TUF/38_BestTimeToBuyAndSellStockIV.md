# [Best Time to Buy and Sell Stock IV](https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_1080698?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos) 🌟🌟🌟

**ONLY K TRANSACTIONS ARE ALLOWED**

### Tabulation Solution

-   All solutions of [best time to buy and sell stock III](./37_BestTimeToBuyAndSellStockIII.md) can be used here, with increasing `cap` to `k`.
-   change everywhere `2` with `k`. take dp array of size `k+1` instead of `3`.
-   **TC: O(NK)**
-   **SC: O(NK)**

```cpp
int maximumProfit(vector<int>& prices, int n, int k)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0))); // change to k+1

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) { // change to k
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
    return dp[0][1][k]; // change to k
}
```

### Space optimized solution

-   **TC: O(NK)**
-   **SC: O(2\*K) = O(K)**

```cpp
int maximumProfit(vector<int> &prices, int n, int k)
{
     vector<vector<int>> curr(2, vector<int>(k+1, 0));
     vector<vector<int>> after(2, vector<int>(k+1, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
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
    return after[1][k];
}
```

### Other Solutions

-   Other approach discussed by striver is already written by me [here](../../Leetcode/188_bestTimeToBuyAndSellStockIV.md).
-   We can also use [these](../../Leetcode/123_bestTimeToBuySellStockIII.md) solutions with initial transactions **2\*K**.
