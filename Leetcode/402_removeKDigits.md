# [402. Remove K Digits](https://leetcode.com/problems/remove-k-digits/) 🌟🌟

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

### Solution
### Code 
```cpp
class Solution {
public:
    string removeKdigits(string num, int k)
    {
        string ans = "";
        for (auto& x : num) {
            while (ans.size() && ans.back() > x && k) {
                ans.pop_back();
                k--;
            }
            if (ans.size() || x != '0')
                ans.push_back(x);
        }
        while (k-- && ans.size())
            ans.pop_back();
        return ans.size() ? ans : "0";
    }
};
```