# [875. Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) 🌟🌟

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

### Brute force (TLE)

-   For every `k` from 1 to `max(piles)`, We check if hour spent is `h` or less.
-   If it is then we return that `k`.
-   **TC: O(n^2)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        long long hoursSpent = 0;
        int mx = *max_element(piles.begin(), piles.end());
        for (double i = 1; i < mx; i++) {
            for (auto& x : piles) {
                hoursSpent += ceil(x / i);
            }
            if (hoursSpent <= h) {
                return i;
            }
            hoursSpent = 0;
        }
        return mx;
    }
};
```

### Binary Search (AC)

-   We can observe that we are checking for every `k` from `1` to `max(piles)`, we can optimize this algorithm by using binary search.
-   Here the main observation for binary search is, if we can finish eating all bananas in `i` hours, then we can finish eating all bananas in `i+1` hours.
-   We need to minimize the result so we check for lesser i if the answer for current i is possible.
-   **TC: O(N\*logM)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int hoursSpent = 0;
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            for (auto& x : piles) {
                hoursSpent += (x / mid) + (x % mid != 0);
            }
            if (hoursSpent <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
            hoursSpent = 0;
        }
        return right;
    }
};
```
