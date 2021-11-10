# [122. Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) 🌟🌟

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

### Recursive - DP

-   [Explanation from (brute force-> dp -> greedy)](<https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/1569135/Explanation-from-(brute-force-greater-dp-greater-greedy)>)

### Greedy - O(N) Time O(1) space (Valley-peak approach)

-   O(2^N) and O(N^2) approaches
-   For each time at lowest cost(valley) we buy stock and at highest cost(peak) we sell stock.

### Code-1

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int i = 0, profit = 0, buy, sell, N = prices.size()-1;
        while (i < N) {
            while (i < N && prices[i + 1] <= prices[i]) {
                i++;
            }
            buy = prices[i];
            while (i < N && prices[i + 1] > prices[i]) {
                i++;
            }
            sell = prices[i];
            profit += sell - buy;
        }
        return profit;
    }
};
```

-   for each day we buy and on next day we sell, **If it is profitable**

### Code-2

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int profit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            if (prices[i - 1] < prices[i])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};
```

### READ:

-   [✅ [Java] Simple & Clean DP solutions for all 6 Buy & Sell Stock questions on LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/1569081/Java-Simple-and-Clean-DP-solutions-for-all-6-Buy-and-Sell-Stock-questions-on-LeetCode)
