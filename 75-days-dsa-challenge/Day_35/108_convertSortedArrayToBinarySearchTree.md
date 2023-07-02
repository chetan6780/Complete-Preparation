# [108. Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)

### Solution

-   We can convert sorted array to BST with the help of binary search.
-   every time mid is our root node and its left will be left of mid and right will be right of mid.
-   **TC: O(N logN)**
-   **SC: O(logN)**

### Code

```cpp
class Solution {
private:
    TreeNode* helper(vector<int>&nums, int l, int r){
        if(l>r) return NULL;
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, l , mid-1);
        root->right = helper(nums, mid+1, r);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0 , nums.size()-1);
    }
};
```
