# [Longest String Chain](https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos) 🌟🌟

### Solution

-   Sort the array of strings in ascending order of their length.
-   The problem now becomes, "find the longest increasing subset of strings"
-   If we can check if two strings are increasing or not then it is same problem as LIS.
-   **TC: O(N^2\*L)**, L is largest length of string.
-   **SC: O(N)**

### Code

```cpp
bool checkPossible(string& s, string& t)
{
    if (s.size() != t.size() + 1) return false;
    int i = 0, j = 0;
    while (i < s.size()) {
        if (j < t.size() && s[i] == t[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }
    if (i == s.size() && j == t.size()) return true;
    return false;
}
int longestStrChain(vector<string>& arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), [](string& a, string& b) {
        return a.size() < b.size();
    });
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (checkPossible(arr[i], arr[prev]) && dp[prev] + 1 > dp[i]) { // LIS Code changed here
                dp[i] = dp[prev] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
```
