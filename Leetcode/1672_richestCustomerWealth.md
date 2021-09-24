# [1672. Richest Customer Wealth](https://leetcode.com/problems/richest-customer-wealth/) 🌟

You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

### O(N^2) Time and O(1) Space solution

- Use inbuilt accumulate function to get the sum of all the elements in the array
- TIP: use &x instead of only x, because it become faster to access with address

---

### Code

```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(auto &x:accounts){
            int temp = accumulate(x.begin(),x.end(),0);
            ans = max(temp,ans);
        }
        return ans;
    }
};
```
