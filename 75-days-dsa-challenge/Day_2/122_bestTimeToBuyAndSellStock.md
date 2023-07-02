# [122. Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) (Medium)

### Recursive Solution (TLE)

-   For current index If we can buy stock, we choose to buy it or not buy it.
-   Similarly if we can sell stock, we choose to sell it or not sell it.
-   In both cases we choose action which gives maximum profit to us.
-   The base case arises when index goes out of bound of array.
-   **TC: O(2^n)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
private:
    int maxProfitRec(vector<int>& prices, int i, bool canBuy)
    {
        if (i >= prices.size())
            return 0;

        if (canBuy) {
            int notBuy = maxProfitRec(prices, i + 1, canBuy);
            int buy = maxProfitRec(prices, i + 1, !canBuy) - prices[i];
            return max(notBuy, buy);
        } else {
            int notSell = maxProfitRec(prices, i + 1, canBuy);
            int sell = maxProfitRec(prices, i + 1, !canBuy) + prices[i];
            return max(notSell, sell);
        }
    }

public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        if (n <= 1)
            return 0;
        return maxProfitRec(prices, 0, true);
    }
};
```

### Memoization

-   The recursive solution is exponential in time complexity so gives TLE.
-   We can use extra space to store the computation of subproblems.(memoization)
-   If we have calculated the subproblem before, we can directly return the result else store new result.
-   **TC: O(n)**
-   **SC: O(n)**

### Code

```cpp
class Solution {
private:
    int maxProfitRec(vector<int>& prices, int i, bool canBuy, vector<vector<int>>& memo)
    {
        if (i >= prices.size())
            return 0;

        if (memo[i][canBuy] != -1)
            return memo[i][canBuy];

        if (canBuy) {
            int notBuy = maxProfitRec(prices, i + 1, canBuy, memo);
            int buy = maxProfitRec(prices, i + 1, !canBuy, memo) - prices[i];
            return memo[i][canBuy] = max(notBuy, buy);
        } else {
            int notSell = maxProfitRec(prices, i + 1, canBuy, memo);
            int sell = maxProfitRec(prices, i + 1, !canBuy, memo) + prices[i];
            return memo[i][canBuy] = max(notSell, sell);
        }
    }

public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        if (n <= 1)
            return 0;
        vector<vector<int>> memo(n + 1, vector<int>(2, -1));
        return maxProfitRec(prices, 0, true, memo);
    }
};
```

### Valley-peak approach

-   For each time at lowest cost(valley) we buy stock and at highest cost(peak) we sell stock.
-   **TC: O(N)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        int buy = 0, sell = 0;
        int i = 0,profit = 0;
        while (i < n - 1) {
            // valley
            while (i < n - 1 && prices[i] >= prices[i + 1])
                i++;
            buy = prices[i];

            // peak
            while (i < n - 1 && prices[i] < prices[i + 1])
                i++;
            sell = prices[i];

            profit += sell - buy;
        }
        return profit;
    }
};
```

### Greedy Solution

-   for each day we buy and on next day we sell, **If it is profitable**
-   **TC: O(N)**
-   **SC: O(1)**

### Code

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
