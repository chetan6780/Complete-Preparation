# [1010. Pairs of Songs With Total Durations Divisible by 60](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/) 🌟🌟

You are given a list of songs where the ith song has a duration of `time[i]` seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by `60`. Formally, we want the number of indices `i, j` such that `i < j` with `(time[i] + time[j]) % 60 == 0`.

### Brute force (TLE)

-   We can find all the pairs from the time array which are divisible by `60`
-   **TC: O(N^2)**
-   **SC: O(1)**

### Hashing Solution

-   `t % 60` gets the remainder from `0 to 59`.
-   We _count the occurrence of each remainders_ in a _array/hashmap_ `mp`.
-   we want to know that, for each `t` in `time`,
-   how many `x` satisfy `(t + x) % 60 = 0`.
-   The straight forward idea is to take `x % 60 = 60 - (t % 60)`, which is valid for the most cases.
-   But, if `t % 60 = 0` then `x % 60` should be `0` instead of `60`.
-   there are two solutions to avoid this situation,
    -   `x % 60 = (60 - t % 60) % 60`,
    -   `x % 60 = (600 - t) % 60`.
-   **TC: O(N)**, Single for loop
-   **SC: O(N)**, for the extra space to store the remainders.

### Code

```cpp
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time)
    {
        vector<int> mp(60);
        int n = time.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int rem = time[i] % 60;
            ans += mp[(60 - rem) % 60];
            mp[rem]++;
        }
        return ans;
    }
};
```
