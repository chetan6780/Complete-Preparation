# Longest Repeated Subsequence

Given a string, find the length of the longest repeating subsequence such that the two subsequences don't have same string character at the same position, i.e., any i'th character in the two subsequences shouldn't have the same index in the original string.

### Prerequisite: [longest common subsequence](./AV11_longestCommonSubSequence.md)

- If we find LCS of string with itself but without repeating same index then it will be longest repeated subsequence.

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
            else if (s1[i - 1] == s2[j - 1] && i != j) // only i!=j added
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[x][y];
}
int LongestRepeatingSubsequence(string s)
{
    int n = s.size();
    return lcs(n, n, s, s);
}
```

### Complexity Analysis

- Time Complexity: **O(N^2)**
- Space Complexity: **O(N^2)**

### References

- GFG: [Longest Repeated Subsequence](https://www.geeksforgeeks.org/longest-repeated-subsequence/)
- YouTube: [AV - Longest Repeated Subsequence](https://www.youtube.com/watch?v=hbTaCmQGqLg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=29)
