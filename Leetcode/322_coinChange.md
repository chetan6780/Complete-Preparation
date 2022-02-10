# [322. Coin Change](https://leetcode.com/problems/coin-change/) 🌟🌟

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

### Recursive solution (TLE)

-   For a coin we have 2 choices:
    -   use it
    -   don't use it
-   if last coin have value less than or equal to amount,we have choice to use or not use it, We return the minimum of the two.
-   else we don't have a choice and we cannot use it, we return not-use.
-   If we use the coin we will increase the count by 1 and subtract the value of the coin from the amount.
-   The base condition arises when the amount is 0, that means we found the answer, return 0
-   and if index goes beyond the limits of the array, that means we cannot use the coin and we return INT_MAX-1.

### Code

```cpp

class Solution {
private:
    int coinChangeRec(vector<int>& coins, int amount, int i)
    {
        if (amount == 0) return 0;
        if (i == 0) return INT_MAX - 1;

        if (coins[i - 1] <= amount) {
            // return min(use(+1), not-use);
            return min(1 + coinChangeRec(coins, amount - coins[i - 1], i), coinChangeRec(coins, amount, i - 1));
        } else {
            // return not-use;
            return coinChangeRec(coins, amount, i - 1);
        }
    }

public:
    int coinChange(vector<int>& coins, int amount)
    {
        int minCoins = coinChangeRec(coins, amount, coins.size());
        return minCoins == INT_MAX - 1 ? -1 : minCoins;
    }
};
```

### Memoization (Top-Down) (AC)

-   The simple recursively solution is not efficient nd results in TLE, because its doing so many calls again and again.
-   We can use a memoization table(dp) to store the results of subproblems.
-   The rest of the code is same, we just need to store new calculated values in the table, if the value is already present then we can return value itself.
-   **TC: O(N\*amount)**
-   **SC: O(N\*amount)**

### Code

```cpp
class Solution {
private:
    int coinChangeRec(vector<int>& coins, int amount, vector<vector<int>>& dp, int i)
    {
        if (amount == 0) return 0;
        if (i == 0) return INT_MAX - 1;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        if (coins[i - 1] <= amount) {
            // return min(use, not-use);
            return dp[i][amount] = min(1 + coinChangeRec(coins, amount - coins[i - 1], dp, i), coinChangeRec(coins, amount, dp, i - 1));
        } else {
            // return not-use;
            return dp[i][amount] = coinChangeRec(coins, amount, dp, i - 1);
        }
    }

public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int minCoins = coinChangeRec(coins, amount, dp, n);
        return minCoins == INT_MAX - 1 ? -1 : minCoins;
    }
};
```

### Tabulation (Bottom-Up) (AC)

-   The memoization solution is acceptable but we can get rid of recursive calls with iterative dp.
-   **TC: O(N\*amount)**
-   **SC: O(N\*amount)**

### Code

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (j == 0) dp[i][j] = 0;
                else if (i == 0) dp[i][j] = INT_MAX - 1;
                else if (coins[i - 1] <= j) {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
    }
};
```

<!-- TODO: 1d DP -->