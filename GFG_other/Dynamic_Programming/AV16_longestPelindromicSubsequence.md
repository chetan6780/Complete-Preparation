# Longest Palindromic Subsequence

Given a sequence, find the length of the longest palindromic subsequence in it.

### Prerequisite: [longest common subsequence](./AV11_longestCommonSubSequence.md)

- Given string a, lcs of string a and its reverse will be the longest palindromic subsequence👍.

### Code

```cpp
int lcs(int x, int y, string s1, string s2)
{
    int dp[x + 1][y + 1];

    for (int i = 0; i < x + 1; i++)
    {
        for (int j = 0; j < y + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[x][y];
}
int lps(int n, string s)
{
    return lcs(n, n, s, reverse(s.begin(), s.end()));
}
```

### Complexity Analysis

- Time Complexity: **O(N^2)**
- Space Complexity: **O(N^2)**

### Reference

- GFG: [Longest Palindromic Subsequence](https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/)
- YouTube: [AV - Longest Palindromic Subsequence](https://www.youtube.com/watch?v=wuOOOATz_IA&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=26)
