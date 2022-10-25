# [Minimum insertions to make a string palindrome](https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0) 🌟🌟

### Solution

-   Minimum insertions required to make string palindrome is nothing but `string size - length of longest palindromic subsequence.`
-   Because we can insert reverse of substrings that are not present in LCS to make string palindrome.
-   **TC: O(n\*n)**
-   **SC: O(n\*n)**

```cpp
int getLengthOfLCS(string& a, string& b)
{
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[n][m];
}

int longestPalindromeSubsequence(string s)
{
    string t = s;
    reverse(t.begin(),t.end());
    return getLengthOfLCS(s,t);
}

int minInsertion(string &str)
{
    return str.size()-longestPalindromeSubsequence(str);
}
``
```
