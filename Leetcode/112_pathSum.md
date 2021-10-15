# [112. Path Sum](https://leetcode.com/problems/path-sum/) 🌟

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

### O(N) Time , recursive

- if root is null return false
- if roots left and right both are null return `root->val==targetSum`.
- else recursively find `targerSum - root->val` in left and right subtree.

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        else if(root->left==NULL && root->right==NULL)
            return root->val==targetSum;
        else
            return hasPathSum(root->left,targetSum-root->val)
            || hasPathSum(root->right,targetSum-root->val);
    }
};
```

### O(N) Time , iterative

**soon...**

<!-- TODO: itterative solution -->

```cpp
class Solution{
public:
    bool hasPathSum(TreeNode *root, int sum){
        stack<TreeNode *> st;
        TreeNode *pre = NULL, *node = root;
        int pathSum = 0;

        while (node || !st.empty()){
            while (node){
                st.push(node);
                pathSum += node->val;
                node = node->left;
            }

            node = st.top();
            if (node->left == NULL && node->right == NULL && pathSum == sum)
                return true;

            if (node->right && pre != node->right){
                node = node->right;
            }
            else{
                pre = node;
                st.pop();
                pathSum -= node->val;
                node = NULL;
            }
        }
        return false;
    }
};
```
