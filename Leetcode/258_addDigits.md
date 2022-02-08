# [258. Add Digits](https://leetcode.com/problems/add-digits/) 🌟

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

### Brute Force

-   Intuitive solution

### Code

```cpp
class Solution {
public:
    int addDigits(int num)
    {
        string s = to_string(num);
        while (s.size() != 1) {
            num = 0;
            for (auto x : s) num += x - '0';
            s = to_string(num);
        }
        return s[0] - '0';
    }
};
```

### Mathematical solution

### Code

```cpp
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};
```
