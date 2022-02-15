# [91. Decode Ways](https://leetcode.com/problems/decode-ways/) 🌟🌟

A message containing letters from A-Z can be encoded into numbers using the following mapping:

```
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
```

To **decode** an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

-   "AAJF" with the grouping (1 1 10 6)
-   "KJF" with the grouping (11 10 6)

Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
Given a string s containing only digits, return the **number** of ways to **decode** it.
The test cases are generated so that the answer fits in a **32-bit** integer.

### Recursive solution (TLE)

-   For a character in string we have 2 choices:
    -   We can use it as single character OR
    -   We can use it as a part of a two-character string
-   The base case arises when we cross length of the string, it means we have decoded all the characters.return 1.
-   And if character in string starts with '0' we cannot decode it, return 0.
-   finally we return `way1+way2` because we want to find all the possible ways to decode the string.
-   **TC: O(2^N)**

### Code

```cpp
class Solution {
private:
    int numDecodingsRec(string& s, int i)
    {
        int n = s.size();
        if (i == n) return 1;
        if (s[i] == '0') return 0;

        int way1 = numDecodingsRec(s, i + 1), way2 = 0;
        if (i < n - 1 && stoi(s.substr(i, 2)) <= 26)
            way2 = numDecodingsRec(s, i + 2);

        return way1 + way2;
    }

public:
    int numDecodings(string s)
    {
        if (s.empty()) return 0;
        return numDecodingsRec(s, 0);
    }
};
```

### Memoization (AC)

-   The recursive solution results in TLE, because of repeated calculation.
-   We can use memoization to store the result of subproblems.
-   If the subproblem is already calculated, we can return the result from the memoization table.
-   **TC: O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
private:
    int dp[101];
    int numDecodingsRec(string& s, int i)
    {
        int n = s.size();
        if (i == n) return 1;
        if (s[i] == '0') return 0;

        if (dp[i] != -1) // if we have already calculated the result, return it.
            return dp[i];

        int way1 = numDecodingsRec(s, i + 1), way2 = 0;
        if (i < n - 1 && stoi(s.substr(i, 2)) <= 26)
            way2 = numDecodingsRec(s, i + 2);
        return dp[i] = way1 + way2; // store the result in the memoization table.
    }

public:
    int numDecodings(string s)
    {
        if (s.empty()) return 0;
        memset(dp, -1, sizeof(dp));
        return numDecodingsRec(s, 0);
    }
};
```

### Tabulation (AC)

-   In tabulation we use iteration to calculate the result.
-   It starts from base case and calculate the result for each subproblem.
-   **TC: O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
public:
    int numDecodings(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<int> dp(n + 1);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0')
                dp[i] = 0;
            else {
                dp[i] = dp[i + 1];
                // The second condition is to check if the string is 1[*] or 2[1-6].
                if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
                    dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};
```
