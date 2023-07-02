# [992. Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/)

### Solution

-   exactly(K) = atMost(K) - atMost(K-1)

### Code

```cpp
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int K)
    {
        return atMostK(nums, K) - atMostK(nums, K - 1);
    }
    int atMostK(vector<int>& A, int K)
    {
        int i = 0, res = 0;
        unordered_map<int, int> count;
        int n = A.size();
        for (int j = 0; j < n; ++j) {
            if (!count[A[j]]++)
                K--;
            while (K < 0) {
                if (!--count[A[i]])
                    K++;
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};
```
