# Palindrome Partitioning

Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome.

For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for a palindrome partitioning of a given string. For example, minimum of 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”. If a string is a palindrome, then minimum 0 cuts are needed. If a string of length n containing all different characters, then minimum n-1 cuts are needed.

### Prerequisite: [Matrix Chain Multiplication(MCM)](./AV20_AV20_matrixChainMultiplication.md)

### Recursive Approach

- If i>=j return 0
- If string is a palindrome, 0 partitions required
- else from i to j-1 calculate min of minPalPartion(s, i, k) + minPalPartion(s, k + 1, j) + 1;
- return min.

### Code

```cpp
bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int minPalPartion(string s, int i, int j)
{
    if (i >= j)
        return 0;
    if (isPalindrome(s, i, j))
        return 0;

    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int count = minPalPartion(s, i, k) + minPalPartion(s, k + 1, j) + 1;
        mn = min(mn, count);
    }
    return mn;
}

int palindromicPartition(string str)
{
    int n = str.size();
    return minPalPartion(str, 0, n - 1);
}
```

---

# DP APPROACHES

### A) Memoization

### Code

```cpp
int dp[501][501];
bool isPalindrome(string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int minPalPartion(string &s, int i, int j)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (isPalindrome(s, i, j))
        return 0;

    dp[i][j] = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int count = minPalPartion(s, i, k) + minPalPartion(s, k + 1, j) + 1;
        dp[i][j] = min(dp[i][j], count);
    }
    return dp[i][j];
}

int palindromicPartition(string str)
{
    memset(dp, -1, sizeof(dp));
    int n = str.size();
    return minPalPartion(str, 0, n - 1);
}
```

### Complexity Analysis

- Time Complexity: **O(n^3)**
- O(n^2) Approch at GFG

### References

- GFG: [Palindrome Partitioning](https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/)
- YouTube: [AV - Palindrome Partitioning](https://www.youtube.com/watch?v=szKVpQtBHh8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=35)
