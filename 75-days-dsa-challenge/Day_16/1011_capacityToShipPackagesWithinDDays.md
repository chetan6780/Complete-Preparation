# [1011. Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)

### Binary search on answer

### Code

```cpp
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days)
    {
        int left = 0, right = 0;
        for (int w : weights) {
            left = max(left, w);
            right += w;
        }
        while (left < right) {
            int mid = (left + right) / 2, need = 1, cur = 0;
            for (int w : weights) {
                if (cur + w > mid) {
                    need +++;
                    cur = 0;
                }
                cur += w;
            }
            if (need > days)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
```
