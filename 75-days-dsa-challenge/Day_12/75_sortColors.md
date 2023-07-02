# [75. Sort Colors](https://leetcode.com/problems/sort-colors/) (Medium)

### O(N log N) Time Complexity with sort function.

- sort the vector using stl `sort()` function.

### O(N)+O(N) Time using counting sort.

- count number of 0's, 1's, and 2's and push them in increasing order according to their frequency.

### O(N) Time, 3 Pointers, dutch national flag algorithm.

- We take 3 pointers low, mid and high.
- low and mid points to 0 while high points to the last element.
- we assume following conditions.
    - Towards the left of low everything is 0.
    - Towards the right of high everything is 2.
    - In between low and high, everything is 1.
- while(mid<=high) we do following.
    - When we encounter 0.
        - we swap low and mid.
        - we increment low and mid.
    - When we encounter 1.
        - we increment mid.
    - When we encounter 2.
        - we swap mid and high.
        - we decrement high.

### Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = 0;

        while (mid <= hi)
        {
            switch (nums[mid])
            {
            case 0:
                swap(nums[lo++], nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid], nums[hi--]);
                break;
            }
        }
    }
};
```
