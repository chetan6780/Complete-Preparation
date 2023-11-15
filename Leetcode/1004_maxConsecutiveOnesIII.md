# [1004. Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/description/?envType=study-plan-v2&envId=leetcode-75) 🌟🌟

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

### Sliding Window

-   If we think of the problem, we can see here we just need to get maximum window size, in which there are no more than k zeros.
-   so we start traversing and if we find 0 we increase 0 count.
-   if 0 count is greater than k, we start removing elements from left side of window, until 0 count is less than or equal to k.
-   we keep track of maximum window size.
-   Return the maximum window size.
-   **TC**: O(n)
-   **SC**: O(1)

### Code

```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int zrCnt = 0, ans = 0;
        while(right < n) {
            if(nums[right] == 0) {
                zrCnt++;
            }
            while(zrCnt > k) {
                if(nums[left] == 0) {
                    zrCnt--;
                }
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
```
