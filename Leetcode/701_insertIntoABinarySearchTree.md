# [701. Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/) 🌟🌟

You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

### O(N) Time solution

- We append the new node to leaf node where it can be place without violating the BST property.
- if value of new node is less than root we try for right child
- else we try for left child.

### Code

```cpp
class Solution{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val){
        if (root == NULL) return new TreeNode(val);

        TreeNode *node = root;
        while (true){
            if (node->val <= val){
                if (node->right != NULL)
                    node = node->right;
                else{
                    node->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if (node->left != NULL)
                    node = node->left;
                else{
                    node->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
```
