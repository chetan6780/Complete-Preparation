# [31. Next Permutation](https://leetcode.com/problems/next-permutation/) (Medium)

### Brute Force

-   We first generate all the permutations and store them in permutations vector.
-   Then we find the given vector in the permutations vector.if we found then we return its next vector as and.
-   If given the last vector return the first vector from the permutations vector.
-   **TC: O(N!\*N)** - Because there are N! orders and N is the length of every array.
-   **SC: O(N!)** - To store the all permutations, there are N! permutations.

### Inbuilt next_permutation

-   we can also solve the problem in-place using in-built `next_permutation(a.being(),a.end())` function in c++.
-   But in an interview this is not expected.

### Code

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums){
        next_permutation(nums.begin(), nums.end());
    }
};
```

### O(N) Time solution.

-   INTUITION:- If we Observe the dictionary of order(permeation order) we can find that there is always Triangle like structure.
-   ALGORITHM:- 1. From back find the _largest index_ `k` such that `nums[k] < nums[k + 1]`. If no such index exists, just reverse `nums` and done.
    2.From back find the _largest index_ `l > k` such that `nums[k] < nums[l]`. 3.`Swap` `nums[k]` and `nums[l]`. 4.`Reverse` the sub-array `nums[k + 1:]`.
-   REFERENCE:- [C++ from Wikipedia(leetcode discussion)](https://leetcode.com/problems/next-permutation/discuss/13867/C%2B%2B-from-Wikipedia)

### Code

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size(), k, l;
        for (k = n - 2; k >= 0; k--) { // Step 1
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
        if (k < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            for (l = n - 1; l > k; l--) { // Step 2
                if (nums[l] > nums[k]) {
                    break;
                }
            }
            swap(nums[k], nums[l]); //Step 3
            reverse(nums.begin() + k + 1, nums.end()); //Step 4
        }
    }
};
```
