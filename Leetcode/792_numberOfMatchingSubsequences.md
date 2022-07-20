# [792. Number of Matching Subsequences](https://leetcode.com/problems/number-of-matching-subsequences/) 🌟🌟

Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

-   For example, "ace" is a subsequence of "abcde".

### Brute Force (TLE)

-   Find all subsequences of s and check if words[i] is in the subsequence.
-   **TC: O(2^n)**

### Optimization (TLE)

-   Instead of finding all subsequences and checking in words array, we can do opposite of it. i.e. we can find if words[i] is subsequence or not.
-   **TC: O(n\*m)**, where n = words.size() and m = s.size()

### Hashmap (AC)

-   We have multiple duplicate words in words array, we can store them and numbers of times they appeared in hashmap and check for subsequence.
-   **TC: O(n\*m)**, where n = hashmap.size() and m = s.size()

### Code

```cpp
class Solution {
    bool isSubsequence(string& s, string& a)
    {
        int n = s.size(), m = a.size();
        if (m > n)
            return false;

        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s[i] == a[j]) {
                j++;
            }
            i++;
        }
        return j == m;
    }

public:
    int numMatchingSubseq(string s, vector<string>& words)
    {
        int res = 0;
        unordered_map<string, int> wordsMap;
        for (auto x : words) {
            wordsMap[x]++;
        }
        for (auto x : wordsMap) {
            string newString = x.first;
            if (isSubsequence(s, newString)) {
                res += x.second;
            }
        }
        return res;
    }
};
```
