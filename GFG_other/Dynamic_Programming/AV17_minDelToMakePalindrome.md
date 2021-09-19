# Minimum number of deletions to make a string palindrome

Given a string of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome.

_Note: The order of characters should be maintained._

### Prerequisite: [Longest Palindromic Subsequence](./AV16_longestPalindromicSubsequence.md)

- LPS is inverly proportional to the number of deletions required.
- If we can find longest palindromic sequence, we can say len_of_string - LPS will be minimum deletions required.

### Mark: This Question is also known - Minimun number of insertion to make palindrome

- minimum number of deletions == minimum number of insertions

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
    string s2 = string(s.rbegin(), s.rend()); // copy reverse of s in s2
    return lcs(n, n, s, s2);
}
int minimumNumberOfDeletions(string S)
{
    int len = S.size();
    int lpsLen = lps(len, S);
    return len - lpsLen;
}
```

### Complexity Analysis

- Time Complexity: **O(len^2)**
- Space Complexity: **O(len^2)**

### References

- GFG: [Minimum number of deletions to make a string palindrome](https://www.geeksforgeeks.org/minimum-number-deletions-make-string-palindrome/)
- YouTube: [AV - Minimum number of deletions to make a string palindrome](https://www.youtube.com/watch?v=CFwCCNbRuLY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=27)
