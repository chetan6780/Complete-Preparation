# [283. Move Zeroes](https://leetcode.com/problems/move-zeroes/) 🌟

### O(N) Time solution

-   We will shift all non zero elements at front
-   Then remaining elements will be filled with zeros

### Code

```cpp
class Solution{
public:
    void moveZeroes(vector<int> &nums)
    {
        int ind = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] != 0)
                nums[ind++] = nums[i];

        while (ind < n)
            nums[ind++] = 0;
    }
};
```

### O(N) Time snowball solution

-   The idea is that we go through the array and gather all zeros on our road.
-   If element is 0, increase size of snowball by 1.
-   else we swap it with (i-snowball)th element.
-   **NOTE:** here we used temp variable instead of direct swapping for avoiding unnecessary swapping. For ex.`[1]` no swap required.

### Code

```cpp
class Solution{
public:
    void moveZeroes(vector<int> &nums)
    {
        int snowBallSize=0,n=nums.size();
        for(int i=0; i < n; i++){
            if(nums[i]==0){
                snowBallSize++;
            }
            else{
                int temp=nums[i];
                nums[i]=0;
                nums[i-snowBallSize]=temp;
            }
        }
    }
};
```

### Optimal solution

-   We maintain two pointers, one for non-zero elements and one for zeros.
-   If we encounter non-zero element, we swap it with the element at index of zero pointer.
-   **TC: O(N)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};
```
