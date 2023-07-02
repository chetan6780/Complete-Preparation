# [1448. Count Good Nodes in Binary Tree](https://leetcode.com/problems/count-good-nodes-in-binary-tree/)

### Pre-order Traversal

-   We maintain `maxVal` variable to store max value seen so far.
-   if root's val is greater than or equal to `maxVal`, increase the count ans update `maxVal` variable.
-   Traverse left and right subtree.

### Code

```cpp
class Solution {
private:
    int ans = 0;
    void preorder(TreeNode* root, int maxVal)
    {
        if (root == NULL) return;
        if (root->val >= maxVal){
            ans++;
            maxVal = root->val;
        }
        preorder(root->left, maxVal);
        preorder(root->right, maxVal);
    }

public:
    int goodNodes(TreeNode* root)
    {
        preorder(root, INT_MIN);
        return ans;
    }
};
```
