# [101. Symmetric Tree](https://leetcode.com/problems/symmetric-tree/) 🌟

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

### O(N) Time solution

- we will trverse left and right subtrees of the root with the same type of traversal.
- we compare the value of left with right or value of right with left , if they are not equal we return false.
- we recurse for left's left with right's right and left's right with right's left.

### Code

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root==NULL || isSymmetricHelp(root->left,root->right);
    }

    bool isSymmetricHelp(TreeNode* left,TreeNode* right){
        if(left==NULL || right==NULL) return left==right;
        if(left->val!=right->val) return false;

        return isSymmetricHelp(left->left,right->right)&&isSymmetricHelp(left->right,right->left);
    }
};
```
