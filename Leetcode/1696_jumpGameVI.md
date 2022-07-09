# [1696. Jump Game VI](https://leetcode.com/problems/jump-game-vii/)

You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.

### Recursion (TLE)

-   Try whats the question asking.
-   For every index try to jump 1 to k steps, and get maximum score.
-   if we reach outside return `nums[n-1]`.
-   **TC: O(k^n)**
-   **SC: O(n)**, Recursion stack

### Code

```cpp

class Solution {
    int helper(vector<int>& nums, int k, int i)
    {
        int n = nums.size();
        if (i >= n - 1) {
            return nums[n - 1];
        }
        int ans = INT_MIN;
        for (int j = 1; j <= k; j++) {
            ans = max(ans, max(ans, nums[i] + helper(nums, k, i + j)));
        }
        return ans;
    }

public:
    int maxResult(vector<int>& nums, int k)
    {
        return helper(nums, k, 0);
    }
};
```

### Memoization (TLE)

-   Memoize the result by storing it in memo array of INT_MIN.
-   **TC: O(k\*n)**
-   **SC: O(n)**, Memoization array

### Code

```cpp

class Solution {
    int helper(vector<int>& nums, int k, int i, vector<int>& memo)
    {
        int n = nums.size();
        if (i >= n - 1) {
            return nums[n - 1];
        }
        if (memo[i] != INT_MIN)
            return memo[i];
        int ans = INT_MIN;
        for (int j = 1; j <= k; j++) {
            ans = max(ans, max(ans, nums[i] + helper(nums, k, i + j, memo)));
        }
        return memo[i] = ans;
    }

public:
    int maxResult(vector<int>& nums, int k)
    {
        vector<int> memo(nums.size(), INT_MIN);
        return helper(nums, k, 0, memo);
    }
};
```

### Tabulation (TLE) 🤕

-   **TC: O(k\*n)**
-   **SC: O(n)**, Memoization array

### Code

```cpp
class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        vector<int> dp(nums.size(), INT_MIN);
        int n = nums.size();
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    dp[i] = max(dp[i], dp[i - j] + nums[i]);
                }
            }
        }
        return dp[n - 1];
    }
};
```

---

> **NOTE: Further Code is from [archit's post][archit's explanation].**

### Tabulation optimization with multiset

-   **TC: O(n log k)**
-   **SC: O(n)**

### Code

```cpp

class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        vector<int> dp(nums.size(), INT_MIN);
        multiset<int> st;
        int n = nums.size();
        dp[0] = nums[0];
        st.insert(dp[0]);
        for (int i = 1; i < n; i++) {
            if (i > k) {
                st.erase(st.find(dp[i - k - 1]));
            }
            dp[i] = *st.rbegin()+nums[i];
            st.insert(dp[i]);
        }
        return dp[n - 1];
    }
};
```

### Further optimization with dequeue

-   **TC: O(n)**
-   **SC: O(n)**

### Code

```cpp
class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        vector<int> dp(nums.size(), INT_MIN);
        deque<int> q;
        int n = nums.size();
        dp[0] = nums[0];
        q.push_front(0);
        for (int i = 1; i < n; i++) {
            if (q.front() < i - k)
                q.pop_front();
            dp[i] = nums[i] + dp[q.front()];
            while (!q.empty() && dp[q.back()] <= dp[i])
                q.pop_back();
            q.push_back(i);
        }
        return dp[n - 1];
    }
};
```

---

### Must read

-   [✅ Optimizations from Brute-Force to Dynamic Programming w/ Explanation][archit's explanation]

<!-- Link -->

[archit's explanation]: https://leetcode.com/problems/jump-game-vi/discuss/1260737/Optimizations-from-Brute-Force-to-Dynamic-Programming-w-Explanation
