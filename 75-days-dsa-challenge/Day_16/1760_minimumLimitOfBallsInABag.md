# [1760. Minimum Limit of Balls in a Bag](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/)

### Binary search on answer

### Code

```cpp
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOps)
    {
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for (int x : nums)
                cnt += (x - 1) / mid;

            if (cnt > maxOps)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
```
