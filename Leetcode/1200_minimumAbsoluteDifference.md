# [1200. Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/) 🌟

Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

-   a, b are from arr
-   a < b
-   b - a equals to the minimum absolute difference of any two elements in arr

### Brute force

-   First we find the minimum difference between all the pairs of array.
-   With brute force, we can find all pairs of elements with the minimum absolute difference of any two elements in O(n^2) time.
-   **TC: O(N^2)**
-   **SC: O(1)**

### Sort + Two traversal

-   We sort the array first.
-   Then we traverse the array from the beginning to the end and find minimum difference.
-   Since array is sorted minimum difference pairs will be adjacent elements of the array.
-   store them in 2D ans vector and return ans.
-   **TC: O(NlogN)**: For sorting
-   **SC: O(logN) || O(N)**: Space required for internal sorting. in C++ its O(logN) for py its O(N).

```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] < minDiff)
                minDiff = arr[i + 1] - arr[i];
        }
        vector<vector<int>> ans;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] == minDiff)
                ans.push_back({ arr[i], arr[i + 1] });
        }

        return ans;
    }
};
```
