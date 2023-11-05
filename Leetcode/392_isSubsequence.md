# [392. Is Subsequence](https://leetcode.com/problems/is-subsequence/) 🌟

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

### Exhaustive Search

-   if size of s is greater than t, then its obvious that s is not a subsequence of t.
-   We will try to find s in t.
-   traverse through s and find every character in t.
-   if at the end out pointer reaches the end of s, then s is a subsequence of t, else not.
-   **TC: O(n)**, where n is the length of t. Each step we either increment the pointer on s or the pointer on t.

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

### Recursive solution

-   base case:
    -   if s is empty, s is a subsequence of t, return true
    -   if t is empty, subsequence of t not found, return false
-   check if first character of s matches with first character of t
    -   if yes, then check for strings starting from next character
    -   if no, then check for strings starting from next character of t with same s
-   **NOTE:** substr(ind, size) function creates new string from string starting from given index to given size(default till end).

### Code

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        if (s.size() == 0) return true;
        if (t.size() == 0) return false;
        if (s[0] == t[0]){ // first character matches
            // check for strings starting from next character
            return isSubsequence(s.substr(1), t.substr(1));
        } else {
            // check for strings starting from next character of t
            return isSubsequence(s, t.substr(1));
        }
    }
};
```

### Dynamic Programming

-   We can use dynamic programming to solve this problem.(specifically map and binary search)
-   We will store the index of every character in t in a map with key as character and value as vector of indices.
-   Now we will iterate over s and for every character in s, we will find the index of that character in t.
-   we should find index greater than the previous index, previous index can be stored in a variable.
-   in between we can not find any character of s in map then return false.
-   also if we reach the end of t and still some characters are left in s, then return false.
-   else return true.
-   **TC: O(nlogn)**, where n is the length of t. Each step we either increment the pointer on s or the pointer on t.
-   **NOTE:** This is best solution if there are many s and we want to check them in same t.(follow up of this problem)

### Code

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int m = s.size(), n = t.size();
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[t[i]].push_back(i);
        }
        int prev = -1;
        for (int i = 0; i < m; i++) {
            if (mp.find(s[i]) == mp.end()) {
                return false;
            }
            auto it = upper_bound(mp[s[i]].begin(), mp[s[i]].end(), prev);
            if (it == mp[s[i]].end()) {
                return false;
            }
            prev = *it;
        }
        return true;
    }
};
```
