# [Longest Increasing Subsequence](https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0) 🌟🌟

### Binary search solution

-   **NOTE:** we cannot print LIS with this solution as we are overwriting the array.
-   Push first element in array.
-   If last element of array is less than current element, push it in array.
-   If last element is greater than current element, find the index of the first element greater than or equal to current element and replace it with current element.
-   Return size of array.
-   **TC: O(nlogn)**
-   **SC: O(n)**

### Code

```cpp
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> arr;
    arr.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr.back()) {
            arr.push_back(arr[i]);
        } else {
            int idx = lower_bound(arr.begin(), arr.end(), arr[i]) - arr.begin();
            arr[idx] = arr[i];
        }
    }
    return arr.size();
}
```
