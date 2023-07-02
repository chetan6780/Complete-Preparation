# [45. Jump Game II](https://leetcode.com/problems/jump-game-ii/) (Medium)

### Solution

### Code

```cpp
class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        int i = 0, j = 0, reachablePlace = 0, jumps = 0;
        while (j < n - 1) {
            reachablePlace = max(reachablePlace, i + nums[i]);
            if (i == j) {
                j = reachablePlace;
                jumps++;
            }
            i++;
        }
        return jumps;
    }
};
```
