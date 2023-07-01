# [236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) 🌟🌟

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

### O(N) Time and O(N) Space

- Find the path from the root node to node n1 and store it in a vector or array.
- Find the path from the root node to node n2 and store it in another vector or array.
- Traverse both paths until the values in arrays are same. Return the common element just before the mismatch.

### O(N) Time recursive solution

- we traverse the tree and find p and q;
- if one of child node is null return another
- else both are not null return the root(curr node), that means left and right are p and q.
- Reference: [link](https://www.youtube.com/watch?v=_-QHfMDde90) for recursive solution.

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root; // both are not null
    }
};
```
