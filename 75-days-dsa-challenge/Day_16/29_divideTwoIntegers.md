# [29. Divide Two Integers](https://leetcode.com/problems/divide-two-integers/)

### Solution

### Code

```cpp
class Solution {
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == divisor)
            return 1;
        bool isPositive = (dividend < 0 == divisor < 0); // if both are of same sign, answer is positive
        unsigned int dividend_p = abs(dividend);
        unsigned int divisor_p = abs(divisor);
        unsigned int ans = 0;
        while (dividend_p >= divisor_p) { // while dividend_p is greater than or equal to divisor_p
            int cnt = 0;
            while (dividend_p > (divisor_p << (cnt + 1)))
                cnt++;
            ans += (1 << cnt); // add the power of 2 found to the answer
            dividend_p = dividend_p - (divisor_p << cnt); // reduce the dividend_p by divisor_p * power of 2 found
        }
        if (ans == (1 << 31) and isPositive) // if ans cannot be stored in signed int
            return INT_MAX;

        return isPositive ? ans : -ans;
    }
};
```
