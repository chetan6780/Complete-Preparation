# [Longest palindromic subsequence](https://www.codingninjas.com/codestudio/problems/longest-palindromic-subsequence_842787) 🌟🌟🌟

### Solution

-   Longest palindromic subsequences nothing but longest common subsequence of string and its reverse.
-   **TC: O(n\*n)**
-   **SC: O(n\*n)**

### Code

```cpp
int longestPalindromeSubsequence(string s)
{
    string t = s;
    reverse(t.begin(),t.end());
    return getLengthOfLCS(s,t);
}
```
