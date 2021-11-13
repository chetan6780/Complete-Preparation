# [Largest subarray with 0 sum](https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1) 🌟

Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

### Brute force

-   We generate all subarrays and find the largest subarray with 0 sum.
-   We can generate subarrays with **O(N^3), O(N^2), O(N)-using kadanes algorithm**

### Hashing Solution

-   **TC: O(N lonN)**
-   **SC:O(N)** for map
-   kind of extension of kadanes algorithm

### Code

```cpp
int maxLen(int A[], int n)
{
    unordered_map<int, int> prefixSum_mp;
    int sum = 0;
    int max_length = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        if (sum == 0) {
            max_length = i + 1;
        } else {
            if (prefixSum_mp.find(sum) != prefixSum_mp.end()) {
                max_length = max(max_length, i - prefixSum_mp[sum]);
            } else {
                prefixSum_mp[sum] = i;
            }
        }
    }
    return max_length;
}

```
