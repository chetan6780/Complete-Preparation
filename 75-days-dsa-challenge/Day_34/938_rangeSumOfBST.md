# [938. Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/)

### Traversal Approaches

-   We can solve this problem with any of the traversal for the tree.
-   We just need to check for the condition of the node value and then add the value to the sum.

### BST Traversal

-   We can use BST properties and avoid extra recursive calls.
-   **TC: O(N)**, N is number of nodes in the tree.
-   **SC: O(h)**, h is the height of the tree.

```cpp
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        if (root == NULL) return 0;
        int sum = 0;
        if (root->val >= low && root->val <= high) sum += root->val;
        if (root->val >= low) sum += rangeSumBST(root->left, low, high);
        if (root->val <= high) sum += rangeSumBST(root->right, low, high);
        return sum;
    }
};
```
