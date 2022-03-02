# [392. Is Subsequence](https://leetcode.com/problems/is-subsequence/) 🌟

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

### Exhaustive Search

### Code

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        if (n > m) return false;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        if (i >= n) return true;
        return false;
    }
};
```

### Dynamic Programming
