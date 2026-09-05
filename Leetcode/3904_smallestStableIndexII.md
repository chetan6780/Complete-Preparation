# [3904. Smallest Stable Index II](https://leetcode.com/problems/smallest-stable-index-ii/) 🌟🌟

You are given an integer array nums of length n and an integer k.

For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).

An index i is called stable if its instability score is less than or equal to k.

Return the smallest stable index. If no such index exists, return -1.

This is the same problem as [3903. Smallest Stable Index I](./3903_smallestStableIndexI.md), but n can be up to 1e5, so the O(n^2) brute force TLEs here — only the O(n) approaches work.

### Prefix Max Array + Suffix Min Array

-   Precompute preMax[i] = max(nums[0..i]) left to right.
-   Precompute suffMin[i] = min(nums[i..n-1]) right to left.
-   Scan once and return the first index where preMax[i] - suffMin[i] <= k.
-   **TC:** O(n)
-   **SC:** O(n)

### Code

**C++**

```cpp
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k)
    {
        int n = nums.size();

        vector<int> preMax(n, -1);
        vector<int> suffMin(n, INT_MAX);

        preMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i - 1], nums[i]);
        }

        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        };

        for (int i = 0; i < n; i++) {
            if ((preMax[i] - suffMin[i]) <= k) {
                return i;
            }
        }
        return -1;
    }
};
```

**Go**

```go
func firstStableIndex(nums []int, k int) int {
    n := len(nums)

    preMax := make([]int, n)
    suffMin := make([]int, n)

    preMax[0] = nums[0]
    for i := 1; i < n; i++ {
        preMax[i] = max(preMax[i-1], nums[i])
    }

    suffMin[n-1] = nums[n-1]
    for i := n - 2; i >= 0; i-- {
        suffMin[i] = min(suffMin[i+1], nums[i])
    }

    for i := 0; i < n; i++ {
        if preMax[i]-suffMin[i] <= k {
            return i
        }
    }
    return -1
}
```

### Running Max + Suffix Min Array

-   Same as above, but the prefix max doesn't need its own array since it only depends on the running value up to i.
-   Precompute suffMin[i] once, then fold the prefix max into a single variable updated while scanning left to right.
-   **TC:** O(n)
-   **SC:** O(n) (suffix min array only)

### Code

**C++**

```cpp
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k)
    {
        int n = nums.size();

        vector<int> suffMin(n, INT_MAX);

        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        };

        int mx = nums[0];
        for (int i = 0; i < n; i++) {
            mx = max(nums[i], mx);
            if ((mx - suffMin[i]) <= k) {
                return i;
            }
        }
        return -1;
    }
};
```

**Go**

```go
func firstStableIndex(nums []int, k int) int {
    n := len(nums)

    suffMin := make([]int, n)

    suffMin[n-1] = nums[n-1]
    for i := n - 2; i >= 0; i-- {
        suffMin[i] = min(nums[i], suffMin[i+1])
    }

    mx := nums[0]
    for i := 0; i < n; i++ {
        mx = max(mx, nums[i])
        if mx-suffMin[i] <= k {
            return i
        }
    }
    return -1
}
```
