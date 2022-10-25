# [Print LCS](./26_PrintLCS.md)

### Solution

-   If we observe dp table of [Longest Common Subsequence](./25_LongestCommonSubsequence.md), we can see that count increases in dp table when both characters are same.
-   We can find that character if we just check where count is increasing in dp table and store it.
-   We traverse from bottom right to top left and store the character when count increases.

### Code

```cpp
void printLCS(string& s1, string& s2, vector<vector<int>>& dp)
{
    int n = s1.size(), m = s2.size();
    int len = dp[n][m];
    int i = n;
    int j = m;

    int index = len - 1;
    string res = "";
    for (int k = 1; k <= len; k++) {
        res += "#"; // dummy string
    }

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            res[index] = s1[i - 1];
            index--;
            i--;
            j--;
        } else if (s1[i - 1] > s2[j - 1]) {
            i--;
        } else
            j--;
    }
    cout << res << endl;
}
```
