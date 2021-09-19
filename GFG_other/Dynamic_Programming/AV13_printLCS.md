# Print Longest Common Subsequence

Given two sequences, print the longest subsequence present in both of them.

### Prerequisite: [longest common subsequence](./AV11_longestCommonSubSequence.md)

- Find lenght of longest common subsequence
- Initialize i and j with n,m
- while both not become 0 we itterate over dp array.
  - if last char of both string is same then we push_back it in resultant string,and decrement both i and j.
  - else if upper row state in dp is max between (upper_row,prev_col) we decrement i.
  - else prev_row is maximum and we decrement j.
- Finally reverse the string because we stored fron last to start.
- Return the string.

### Code

```cpp
string lcsPrint(int x, int y, string s1, string s2)
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
                dp[i][j] = 0;
        }
    }
    string res;
    int i = x, j = y;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            res.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(res.begin(), res.end());
    return res;
}
```

### Complexity Analysis

- Time Complexity: **O(X\*Y)**
- Space Complexity: **O(X\*Y)**

### References

- GFG: [Print longest common subsequence](https://www.geeksforgeeks.org/printing-longest-common-subsequence/)
- Youtube: [AV - print longest common subsequence](https://www.youtube.com/watch?v=x5hQvnUcjiM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=23&t=2075s)
