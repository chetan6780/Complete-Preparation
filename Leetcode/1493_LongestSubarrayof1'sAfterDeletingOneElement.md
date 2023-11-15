# [1493. Longest Subarray of 1's After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/) 🌟🌟

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

### Sliding Window

-   This question is same as [1004. Max Consecutive Ones III](./1004_maxConsecutiveOnesIII.md) 🌟🌟
-   Here we just need to maintain a window of at most 1 zero.
-   return window size - 1, as we need to remove at least 1 element(either 0 or 1).
-   **TN**: O(N)
-   **SC**: O(1)

### Code

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int cnt = 0, ans = 0, n = nums.size();
        while(right<n){
            if(nums[right]==0){
                cnt++;
            }
            while(cnt>1){
                if(nums[left]==0)cnt--;
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans-1;
    }
};
```
