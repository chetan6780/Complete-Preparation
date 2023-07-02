# [404. Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/)

### Solution

-   We use bool variable `isLeft` to indicate whether the current node is left child or not.
-   Rest is just sum of leaf node with `isLeft = true`.

### Code

```cpp
class Solution {
private:
    int sum = 0;

public:
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false)
    {
        if (root == NULL) return 0;
        if (isLeft && root->left == NULL && root->right == NULL) sum += root->val;
        sumOfLeftLeaves(root->left, true);
        sumOfLeftLeaves(root->right, false);
        return sum;
    }
};
```
