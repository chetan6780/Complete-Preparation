# [1502. Can Make Arithmetic Progression From Sequence](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/) 🌟

A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

### Simple Solution

-   Sort the array.
-   Check if the difference between any two consecutive elements is the same or not.
-   **TC: O(NlogN)**: For sorting
-   **SC: O(1)**: Excluding sorting space, No extra space required. OR
-   **SC: O(logN) || O(N)**: Considering Space required for internal sorting. in C++ its O(logN) for py its O(N).

### Code

```cpp
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for (int i = 1; i < n - 1; i++) {
            if (arr[i - 1] - arr[i] != arr[i] - arr[i + 1])
                return false;
        }
        return true;
    }
};
```
