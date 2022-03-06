# [1359. Count All Valid Pickup and Delivery Options](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/) 🌟🌟

Given n orders, each order consist in pickup and delivery services.

Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i).

Since the answer may be too large, return it modulo 10^9 + 7.

### DP Solution

### Code

```cpp
typedef long long ll;
class Solution {
public:
    int countOrders(int n)
    {
        vector<ll> dp(n + 1, 0);
        dp[0] = 1;
        ll mod = pow(10, 9) + 7;

        for (ll i = 1; i <= n; i++) {
            dp[i] = i * dp[i - 1] * (2 * i - 1);
            dp[i] = dp[i] % mod;
        }

        return dp[n];
    }
};
```
