# [169. Majority Element](https://leetcode.com/problems/majority-element/) (Easy)

### O(N^2) Brute force

-   For every number in array we count its occurrences.
-   If count is greater than n/2, then we return the number.

### O(N)Time with extra space

-   we Can take a vector or unordered_map to store the frequency of each element.
-   We traverse the hash map/ vector to find the n/2 frequency.
-   if we found we return the element.
-   **TC: O(N)**
-   **SC:O(N)/O(N^2)** - _Yes if we use unordered_map it's worst case time complexity is **O(N^2)**, which occurs when all elements are divisible by prime number and result in collision_. But if we use frequency vector it's worst case time complexity is **O(N)**.

### Moore's Voting Algorithm

-   **TC:O(N)**
-   **SC:O(1)**
-   We maintain 2 variables count and candidate.
-   We traverse the array and for every element we do following:
    -   If count is 0, then we set candidate as current element.
    -   If current element is same as candidate, then we increment count by 1.
    -   else we decrement count by 1.
-   return candidate.

```cpp
class Solution {
public:
    // moore's voting algorithm
    int majorityElement(vector<int>& nums)
    {
        int count = 0;
        int candidate = 0;
        for (int x : nums) {
            if (count == 0) {
                candidate = x;
            }
            // count += (x == candidate) ? 1 : -1;
            if (x == candidate) count++;
            else count--;
        }
        return candidate;
    }
};
```
